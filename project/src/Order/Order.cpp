/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Order
*/

#include "Order.hpp"

Order::Order(std::size_t orderNb, PizzaType const &type, PizzaSize const &size) :
    _orderNb(orderNb), _type(type), _size(size)
{
}

Order::~Order()
{
}

std::size_t Order::getOrderNb() const
{
    return _orderNb;
}

PizzaType Order::getType() const
{
    return _type;
}

PizzaSize Order::getSize() const
{
    return _size;
}

Order &Order::operator =(Order const &order)
{
    _orderNb = order.getOrderNb();
    _type = order.getType();
    _size = order.getSize();
    return *this;
}
