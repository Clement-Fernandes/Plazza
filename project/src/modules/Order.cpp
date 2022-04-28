/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Order
*/

#include "Order.hpp"

Order::Order(PizzaType const &type, PizzaSize const &size)
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
