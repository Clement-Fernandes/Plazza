/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include <iostream>
    #include <thread>
    #include <map>
    #include <memory>
    #include <vector>
    #include "Order.hpp"
    #include "enum.hpp"

    #include "Fridge.hpp"
    #include "Cook.hpp"

class Kitchen {
    public:
        Kitchen(float cookingTime, size_t nbCooks, int ingredientTime, int writer, int reader);
        ~Kitchen();

        void loop();

    protected:
    private:
        float _cookingTime;
        size_t _nbCooks;
        int _ingredientTime;
        int _writer;
        int _reader;
        std::vector<Order> _orderList;
        std::vector<Cook> _cooks;
        Fridge _fridge;
        // std::vector<std::thread> _cooksThread;
        // std::vector<std::map<Ingredients, size_t>> _ingredients;

};

#endif /* !KITCHEN_HPP_ */
