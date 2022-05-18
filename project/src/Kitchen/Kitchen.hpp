/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include <thread>
    #include <memory>
    #include <queue>
    #include "Order.hpp"
    #include "IPC.hpp"
    #include "Clock.hpp"
    #include "Cook.hpp"
    #include "ThreadPool.hpp"

class Kitchen {
    public:
        Kitchen(std::size_t id, float cookingTime, std::size_t nbCooks, int ingredientTime, std::shared_ptr<IPC> writer, std::shared_ptr<IPC> reader, std::shared_ptr<Log> log);
        ~Kitchen();

        void loop();
        void displayStatus(void);
        void refillIngredients(std::shared_ptr<Fridge> fridge);

    protected:
    private:
        /* id is to status && log datas */
        std::size_t _id;
        std::shared_ptr<Log> _log;

        /* specify when the kitchen need to close */
        bool _isRunning;

        /* Basics argument (send at execute time) */
        float _cookingTime;
        std::size_t _nbCooks;
        int _ingredientTime;

        /* Clock */
        Clock _clock;

        /* IPC to communicate with the reception */
        std::shared_ptr<IPC> _writer;
        std::shared_ptr<IPC> _reader;

        /* message get in _reader */
        std::string _message;

        /* Contain the list of cooks of the kitchen */
        std::vector<Cook> _cooks;

        /* Contain all ingredients of the kitchen */
        std::shared_ptr<Fridge> _fridge;

        /* Contain the list of order in the kitchen */
        std::queue<Order> _orderList;

        /* Contain the list of queues of order List of each cook */
        std::vector<std::queue<Order>> _orderCookList;

        ThreadPool _threadPool;

        /* Fridge */
        std::thread _fridgeThread;
        std::mutex _mutexFridge;

};

#endif /* !KITCHEN_HPP_ */
