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
        Kitchen(float cookingTime, size_t nbCooks, int ingredientTime, IPC writer, IPC reader);
        ~Kitchen();

        void loop();

    protected:
    private:
        float _cookingTime;
        size_t _nbCooks;
        int _ingredientTime;
        IPC _writer;
        IPC _reader;
        Fridge _fridge;
        std::vector<Order> _orderList;
        std::vector<Cook> _cooks;
        std::string _message;
        bool _isRunning;
        std::vector<std::thread> _cooksThread;
        // std::vector<std::map<Ingredients, size_t>> _ingredients;

};

#endif /* !KITCHEN_HPP_ */
