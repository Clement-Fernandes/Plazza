/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** setOrder
*/

#include "plazza.hpp"
#include "Error.hpp"
#include "Reception.hpp"


PizzaType Reception::getType(std::string const &str) const
{
    PizzaType type;

    try {
        type = _allType.at(str);
    } catch (std::out_of_range const &) {
        throw Error::Order("Pizza type doesn't exist.");
    }
    return type;
}

PizzaSize Reception::getSize(std::string const &str) const
{
    PizzaSize size;

    try {
        size = _allSize.at(str);
    } catch (std::out_of_range const &) {
        throw Error::Order("Pizza size doesn't exist.");
    }
    return size;
}

std::size_t Reception::getNumber(std::string const &str) const
{
    std::string tmp = str;
    std::size_t number = 0;

    tmp.erase(0, 1);
    try {
        number = std::stoi(tmp);
    } catch (std::out_of_range const &) {
        throw Error::Order("Number out of range.");
    }
    return number;
}

void Reception::setOrders(std::vector<std::string> const &commands)
{
    std::vector<Order> orderList;

    *_log << "Order set on number " + std::to_string(_orderNb);
    for (auto &i : commands) {
        std::vector<std::string> orderStr = strToWordArr(i, ' ');
        PizzaType type = getType(orderStr.at(0));
        PizzaSize size = getSize(orderStr.at(1));
        std::size_t nb = getNumber(orderStr.at(2));

        for (std::size_t y = 0; y != nb; y++)
            orderList.push_back(Order(_orderNb, type, size));
    }
    _orders.insert({_orderNb, orderList});
    orderDistribution(orderList);
    _orderNb++;
}