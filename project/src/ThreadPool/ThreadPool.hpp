/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_

    #include <vector>
    #include <thread>
    #include <mutex>
    #include <condition_variable>
    #include <queue>
    #include "Fridge.hpp"
    #include "Order.hpp"
    #include "Log.hpp"

class ThreadPool {
    public:
        ThreadPool(std::shared_ptr<Log> log, std::size_t nbThread, float cookingTime, std::shared_ptr<Fridge> fridge);
        ~ThreadPool();

        void stop();

        void notify();
        void queueJob(Order const &order);

    protected:
    private:
        void threadLoop(float cookingTime, std::shared_ptr<Fridge> fridge);

        std::shared_ptr<Log> _log;
        std::size_t _nbThread;

        std::shared_ptr<Fridge> _fridge;

        bool _stop;
        std::vector<std::thread> _threadsList;
        std::size_t _inactiveCook;

        std::mutex _mutexQueue;
        std::condition_variable _mutexCondition;


        std::queue<Order> _order;
        std::vector<Ingredients> _ingredientList;
};

#endif /* !THREADPOOL_HPP_ */
