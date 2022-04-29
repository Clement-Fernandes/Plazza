/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Order
*/

#ifndef ORDER_HPP_
    #define ORDER_HPP_

    #include "enum.hpp"

class Order {
    public:
        Order(PizzaType const &type, PizzaSize const &size);
        ~Order();
    public:
        PizzaType getType(void) const;
        PizzaSize getSize(void) const;

    private:
        PizzaType _type;
        PizzaSize _size;

};

#endif /* !ORDER_HPP_ */
