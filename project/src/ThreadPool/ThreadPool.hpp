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

        void start(std::size_t nbThread, std::shared_ptr<Fridge> Fridge, float cookingTime);
        void QueueJob(Order const &order);//std::function<void(Order const &)> const &job, 
        void Stop();

    private:
        void ThreadLoop(std::shared_ptr<Fridge> fridge, float cookingTime);

        bool _stop = false;
        std::mutex _mutexQueue;
        std::condition_variable _mutexCondition;
        std::mutex _mutexFridge;
        std::condition_variable _fridgeCondition;

        std::vector<std::thread> _threadsList;
        // std::queue<std::function<void(Order const &)>> _jobs;
        std::queue<Order> _order;
    protected:
    private:
};

#endif /* !THREADPOOL_HPP_ */
