/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** ThreadPool
*/

#include "Cook.hpp"
#include "ThreadPool.hpp"

ThreadPool::ThreadPool()
{
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::start(std::size_t nbThread)
{
    _threadsList.resize(nbThread);
    for (uint32_t i = 0; i < nbThread; i++) {
        _threadsList.at(i) = std::thread(&ThreadPool::ThreadLoop, this);
    }
}

void ThreadPool::ThreadLoop() // Cook life
{
    Cook cook;

    while (!_stop) {
        // std::function<void(Order const &)> job;
        Order order;

        {
            std::unique_lock<std::mutex> lock(_mutexQueue);
            _mutexCondition.wait(lock, [this] {
                return !_order.empty() || _stop;
            });
            if (_stop)
                return;
            // job = _jobs.front();
            // _jobs.pop();
            order = _order.front();
            _order.pop();
        }
        cook.cookPizza(order);
        // job(order);
    }
}

void ThreadPool::QueueJob(Order const &order) //std::function<void(Order const &)> const &job, 
{
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
        // _jobs.push(job);
        _order.push(order);
    }

    _mutexCondition.notify_one();
}

void ThreadPool::Stop()
{
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
        _stop = true;
    }
    _mutexCondition.notify_all();
    for (auto &thread : _threadsList)
        thread.join();
    _threadsList.clear();
}
