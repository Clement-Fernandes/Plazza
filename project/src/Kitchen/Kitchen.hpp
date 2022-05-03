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
        Kitchen(int id, float cookingTime, size_t nbCooks, int ingredientTime, IPC writer, IPC reader);
        ~Kitchen();

        void loop();
        bool handleMessage(std::string const &message);
        void displayStatus(void);

    protected:
    private:
        /* id is to status && log datas */
        int _id;

        /* specify when the kitchen need to close */
        bool _stop;

        /* Basics argument (send at execute time) */
        float _cookingTime;
        size_t _nbCooks;
        int _ingredientTime;

        /* IPC to communicate with the reception */
        IPC _writer;
        IPC _reader;

        /* Contain the list of cooks of the kitchen */
        std::vector<Cook> _cooks;

        /* Contain all ingredients of the kitchen */
        Fridge _fridge;

        /* Contain the list of order in the kitchen */
        std::vector<Order> _orderList;

        int keep = 5;
        // std::vector<std::thread> _cooksThread;
};

#endif /* !KITCHEN_HPP_ */
