/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

    // #include <string>
    // #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <map>
    #include "enum.hpp"
    #include "Error.hpp"
    #include "Kitchen.hpp"

class Reception {
    public:
        Reception();
        ~Reception();

        void terminalReader();
        void orderDistribution();
        void actionKitchen();

        size_t getNbCooks() const;
        float getCookingTime() const;
        void printDebug() const;

    protected:
    private:
        size_t _nbCooks;
        float _cookingTime;
        // std::map<int, std::vector<PizzaType, PizzaSize>> _orders;
        std::vector<std::unordered_map<std::string, int>> _listKitchen;
};

#endif /* !RECEPTION_HPP_ */
