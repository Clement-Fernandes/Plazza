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
        Order(PizzaType const &type, PizzaSize const &size);
        ~Order();

        Order &operator =(Order const &order);
    public:
        PizzaType getType(void) const;
        PizzaSize getSize(void) const;
        // std::string getName(void) const;

    private:
        PizzaType _type;
        PizzaSize _size;
        // std::string _name;

};

#endif /* !ORDER_HPP_ */
