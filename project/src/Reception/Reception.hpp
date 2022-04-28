/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include <map>
    #include "Order.hpp"

class Reception {
    public:
        Reception();
        ~Reception();

        void displayStatus(void) const;
        bool handleRequest(std::string const &data) const;
        void terminalReader();

        void setOrders(std::vector<std::string> const &commands);
        PizzaType getType(std::string const &type) const;
        PizzaSize getSize(std::string const &str) const;
        size_t getNumber(std::string const &str) const;


    protected:
    private:
        std::map<int, std::vector<Order>> _orders;
        size_t _orderNb = 0;
        std::map<std::string, PizzaType> _allType = {
            {"americana", PizzaType::Americana},
            {"fantasia", PizzaType::Fantasia},
            {"margarita", PizzaType::Margarita},
            {"regina", PizzaType::Regina},
        };
         std::map<std::string, PizzaSize> _allSize = {
            {"S", PizzaSize::S},
            {"M", PizzaSize::M},
            {"L", PizzaSize::L},
            {"XL", PizzaSize::XL},
            {"XXL", PizzaSize::XXL},
        };
};

#endif /* !RECEPTION_HPP_ */
