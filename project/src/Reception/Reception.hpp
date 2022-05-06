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
    #include <unordered_map>
    #include "Error.hpp"
    #include "Kitchen.hpp"
    #include "Process.hpp"

class Reception {
    public:
        Reception(float cookingTime, std::size_t nbCook, int ingredientTime);
        ~Reception();

        void analyseOrder(std::string const &data);

        // Reception.cpp
        void displayStatus(void);
        void exitPlazza(void);
        // bool handleSpecialRequest(std::string const &data);

        std::size_t getNbCooks() const;
        float getCookingTime() const;
        void printDebug() const;
        void closeKitchen();

        // orderDistribution.cpp
        void orderDistribution(std::vector<Order> const &orderList);
        void addKitchen(std::size_t id);

        // setOrder.cpp
        void setOrders(std::vector<std::string> const &commands);
        PizzaType getType(std::string const &type) const;
        PizzaSize getSize(std::string const &str) const;
        std::size_t getNumber(std::string const &str) const;

        enum Com {
            Read = 0,
            Write = 1
        };

    protected:
    private:
        bool _isRunning = true;
        std::map<int, std::vector<Order>> _orders;
        std::size_t _orderNb = 0;
        float _cookingTime;
        std::size_t _nbCooks;
        int _ingredientTime;
        std::string _message;
        std::vector<Process> _allProcesses;
        std::vector<std::unordered_map<std::string, IPC>> _listKitchen;
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
