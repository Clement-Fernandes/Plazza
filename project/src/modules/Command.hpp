/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Command
*/

#ifndef COMMAND_HPP_
    #define COMMAND_HPP_

    #include <string>
    #include <vector>
    #include <map>
    #include "Order.hpp"

struct UserOrder
{
    PizzaSize _size;
    PizzaType _type;
    size_t _number;
};

class Command {
    public:
        Command(std::vector<std::string> const &commandLine);
        ~Command();

        void pack();
        void unpack();
    protected:
    private:
        std::vector<Order> _orders;
        std::vector<UserOrder> _userOrders;
        std::map<std::string, PizzaType> const _allType = {
            {"americana", PizzaType::Americana},
            {"fantasia", PizzaType::Fantasia},
            {"margarita", PizzaType::Margarita},
            {"regina", PizzaType::Regina},
        };
         std::map<std::string, PizzaSize> const _allSize = {
            {"S", PizzaSize::S},
            {"M", PizzaSize::M},
            {"L", PizzaSize::L},
            {"XL", PizzaSize::XL},
            {"XXL", PizzaSize::XXL},
        };
};

#endif /* !COMMAND_HPP_ */
