/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Order
*/

#ifndef ORDER_HPP_
    #define ORDER_HPP_

    #include <string>
    #include "enum.hpp"

class Order {
    public:
        Order() {};
        Order(std::size_t orderNb, PizzaType const &type, PizzaSize const &size);
        ~Order();

        Order &operator =(Order const &order);
    public:
        std::size_t getOrderNb() const;
        PizzaType getType() const;
        PizzaSize getSize() const;

    private:
        std::size_t _orderNb;
        PizzaType _type;
        PizzaSize _size;

};

#endif /* !ORDER_HPP_ */
