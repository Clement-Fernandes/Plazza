/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** ThreadPool
*/

#include "Cook.hpp"
#include "plazza.hpp"
#include "ThreadPool.hpp"

#include <chrono>

ThreadPool::ThreadPool(std::shared_ptr<Log> log, std::size_t kitchenId, std::size_t nbThread, float cookingTime, std::shared_ptr<Fridge> fridge) :
 _log(log), _kitchenId(kitchenId), _nbThread(nbThread), _fridge(fridge), _stop(false), _inactiveCook(_nbThread)
{
    _threadsList.resize(_nbThread);
    for (std::size_t i = 0; i < _nbThread; i++)
        _threadsList.at(i) = std::thread(&ThreadPool::threadLoop, this, cookingTime, i);
}

ThreadPool::~ThreadPool()
{
}

void ThreadPool::stop()
{
    _stop = true;
    _mutexCondition.notify_all();
    for (auto &thread : _threadsList)
        thread.join();

}

void ThreadPool::threadLoop(float cookingTime, std::size_t id)
{
    Cook cook(cookingTime, _fridge);

    while (!_stop) {
        Order order;
        {
            std::unique_lock<std::mutex> lock(_mutexQueue);
            _mutexCondition.wait(lock);
            if (_stop)
                return;
            _inactiveCook -= 1;
            order = _order.front();
            *_log << "cook " + std::to_string(id) + " of kitchen " + std::to_string(_kitchenId) + " accepted order " + std::to_string(order.getOrderNb());
            _order.pop();
        }
        _ingredientList.clear();
        _ingredientList = cook.getPizzaIngredients(order);
        if (!_fridge->getIngredients(_ingredientList)) {
            {
                std::unique_lock<std::mutex> lock(_fridge->mutex);

                _fridge->condition.wait(lock, [this] {
                    return _fridge->getIngredients(_ingredientList);
                });
            }
        }
        std::chrono::milliseconds bakingTime(cook.getCookingTime(order));
        std::this_thread::sleep_for(bakingTime * cookingTime);
        *_log << "cook " + std::to_string(id) + " of kitchen " + std::to_string(_kitchenId) + " finished to cook order " + std::to_string(order.getOrderNb());
        {
            std::unique_lock<std::mutex> lock(_mutexQueue);
            _inactiveCook += 1;
            notify();
        }
    }
}

void ThreadPool::notify()
{
    if (!_order.empty())
      _mutexCondition.notify_one();
}

void ThreadPool::queueJob(Order const &order)
{
    {
        std::unique_lock<std::mutex> lock(_mutexQueue);
        _order.push(order);
    }
    if (_inactiveCook > 0)
        _mutexCondition.notify_one();
}

std::size_t ThreadPool::getInactiveCook() const
{
    return _inactiveCook;
}

std::size_t ThreadPool::getQueueSize() const
{
    return _order.size();
}
