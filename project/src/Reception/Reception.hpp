/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include <map>
    #include <any>
    #include <memory>
    #include <unordered_map>
    #include "Error.hpp"
    #include "Kitchen.hpp"
    #include "Process.hpp"
    #include "Log.hpp"

class Reception {
    public:
        // Reception.cpp
        Reception(float cookingTime, std::size_t nbCook, int ingredientTime);
        ~Reception();

        std::size_t getNbCooks() const;
        float getCookingTime() const;
        int getIngredientTime() const;

        void displayStatus();

        void analyseOrder(std::string const &data);

        void printDebug() const;

        // setOrder.cpp
        void setOrders(std::vector<std::string> const &commands);
        PizzaType getType(std::string const &type) const;
        PizzaSize getSize(std::string const &str) const;
        std::size_t getNumber(std::string const &str) const;

        // orderDistribution.cpp
        void orderDistribution(std::vector<Order> const &orderList);
        void addKitchen(std::size_t id);

        enum Com {
            Read = 0,
            Write = 1
        };

    protected:
    private:
        float _cookingTime;
        std::size_t _nbCooks;
        int _ingredientTime;

        /* All existing pizza type */
        std::map<std::string, PizzaType> _allType = {
            {"americana", PizzaType::Americana},
            {"fantasia", PizzaType::Fantasia},
            {"margarita", PizzaType::Margarita},
            {"regina", PizzaType::Regina},
        };
        /* All existing pizza size */
        std::map<std::string, PizzaSize> _allSize = {
            {"S", PizzaSize::S},
            {"M", PizzaSize::M},
            {"L", PizzaSize::L},
            {"XL", PizzaSize::XL},
            {"XXL", PizzaSize::XXL},
        };

        /* List of all orders */
        std::size_t _orderNb = 0;
        std::map<int, std::vector<Order>> _orders;

        std::shared_ptr<Log> _log;

        std::string _message;
        std::vector<Process> _allProcesses;
        std::vector<std::unordered_map<std::string, std::shared_ptr<IPC>>> _listKitchen;
};

#endif /* !RECEPTION_HPP_ */
