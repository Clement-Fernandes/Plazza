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
    #include "Order.hpp"
    #include "IPC.hpp"
    #include "Cook.hpp"

class Kitchen {
    public:
        Kitchen(size_t id, float cookingTime, size_t nbCooks, int ingredientTime, IPC writer, IPC reader);
        ~Kitchen();

        void loop();
        bool handleMessage(void);
        void displayStatus(void);

    protected:
    private:
        // /* id is to status && log datas */
        size_t _id;

        /* specify when the kitchen need to close */
        bool _isRunning;

        /* Basics argument (send at execute time) */
        float _cookingTime;
        size_t _nbCooks;
        int _ingredientTime;

        /* IPC to communicate with the reception */
        IPC _writer;
        IPC _reader;

        /* message get in _reader */
        std::string _message;

        /* Contain the list of cooks of the kitchen */
        std::vector<Cook> _cooks;

        /* Contain all ingredients of the kitchen */
        Fridge _fridge;

        /* list of cooks Thread */
        std::vector<std::thread> _cooksThread;
        // std::vector<std::map<Ingredients, size_t>> _ingredients;

        /* Contain the list of order in the kitchen */
        std::vector<Order> _orderList;

};

#endif /* !KITCHEN_HPP_ */
