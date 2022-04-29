/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Order
*/

#include "Order.hpp"

Order::Order(PizzaType const &type, PizzaSize const &size, std::string const &name) :
    _type(type), _size(size), _name(name)
{
}

Order::~Order()
{
}

PizzaType Order::getType(void) const
{
    return _type;
}

PizzaSize Order::getSize(void) const
{
    return _size;
}

std::string Order::getName(void) const
{
    return _name;
}
