/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** ThreadPool
*/

#include "Cook.hpp"
#include "ThreadPool.hpp"
#include "plazza.hpp"

extern std::mutex fridgeMutex;
extern std::condition_variable fridgeCondition;

ThreadPool::ThreadPool()
{
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::start(std::size_t nbThread, std::shared_ptr<Fridge> fridge, float cookingTime, std::shared_ptr<Log> log)
{
    _log = log;
    std::cout << "start" << std::endl;
    _threadsList.resize(nbThread);
    for (uint32_t i = 0; i < nbThread; i++) {
        _threadsList.at(i) = std::thread(&ThreadPool::threadLoop, this, fridge, cookingTime);
    }
    printText("started");
}

void ThreadPool::threadLoop(std::shared_ptr<Fridge> fridge, float cookingTime)
{
    std::cout << "thread_loop"<< std::endl;
    Cook cook(fridge, cookingTime);

    while (!_stop) {
        Order order;

        {
            std::unique_lock<std::mutex> lock(_mutexQueue);
            _mutexCondition.wait(lock, [this] {
                return !_order.empty() || _stop;
            });
            if (_stop)
                return;
            order = _order.front();
            _order.pop();
        }
        _ing.clear();
        _ing = cook.getPizzaIngredients(order);
        if (!fridge->getIngredients(_ing)) {
            std::cout << "empty" << std::endl;
            {
            std::unique_lock<std::mutex> lock(fridgeMutex);
            fridgeCondition.wait(lock, [this] {
                return _fridge->getIngredients(_ing);
            });
            }
            std::cout << "not empty" << std::endl;
        }
    }
}

void ThreadPool::QueueJob(Order const &order)
{
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
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
