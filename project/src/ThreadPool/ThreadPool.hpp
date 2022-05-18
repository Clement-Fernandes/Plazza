/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
    #define THREADPOOL_HPP_

    #include <vector>
    #include <functional>
    #include <condition_variable>
    #include <thread>
    #include <queue>
    #include <mutex>
    #include "Order.hpp"

class ThreadPool {
    public:
        ThreadPool();
        ~ThreadPool();

        void start(std::size_t nbThread, std::shared_ptr<Fridge> Fridge, float cookingTime, std::shared_ptr<Log> log);
        void QueueJob(Order const &order);
        void Stop();

    private:
        void threadLoop(std::shared_ptr<Fridge> fridge, float cookingTime);

        std::shared_ptr<Log> _log;

        bool _stop = false;
        std::mutex _mutexQueue;
        std::condition_variable _mutexCondition;

        std::vector<std::thread> _threadsList;
        std::shared_ptr<Fridge> _fridge;

        std::queue<Order> _order;
        std::vector<Ingredients> _ing;
    protected:
    private:
};

#endif /* !THREADPOOL_HPP_ */
