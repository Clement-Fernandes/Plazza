/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    // #include <thread>
    #include <memory>
    #include <queue>
    #include "Order.hpp"
    #include "IPC.hpp"
    #include "Clock.hpp"
    #include "ThreadPool.hpp"
    #include "Fridge.hpp"
    #include "Log.hpp"

class Kitchen {
    public:
        Kitchen(std::size_t id, std::shared_ptr<Log> log, float cookingTime, std::size_t nbCooks, int ingredientTime, std::shared_ptr<IPC> writer, std::shared_ptr<IPC> reader);
        ~Kitchen();

        std::size_t loop();
        void displayStatus(void);
        // void refillIngredients(std::shared_ptr<Fridge> fridge);

    protected:
    private:
        /* id is to status && log datas */
        std::size_t _id;
        std::shared_ptr<Log> _log;

        /* Basics argument (send at execute time) */
        float _cookingTime;
        std::size_t _nbCooks;
        int _ingredientTime;

        /* IPC to communicate with the reception */
        std::shared_ptr<IPC> _writer;
        std::shared_ptr<IPC> _reader;

        /* specify when the kitchen need to close */
        bool _isRunning;

        /* Clock */
        Clock _clock;

        /* Contain the list of order in the kitchen */
        std::queue<Order> _orderList;

        /* Fridge */
        std::shared_ptr<Fridge> _fridge;
        // std::thread _fridgeThread;
        // std::mutex _mutexFridge;

        /* ThreadPool containing all cooks */
        ThreadPool _threadPool;

        // /* Contain the list of queues of order List of each cook */
        // std::vector<std::queue<Order>> _orderCookList;



};

#endif /* !KITCHEN_HPP_ */
