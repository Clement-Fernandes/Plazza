/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include <map>
    #include <vector>
    #include <memory>
    #include <unordered_map>
    #include "Process.hpp"
    #include "Log.hpp"
    #include "IPC.hpp"
    #include "Order.hpp"

class Reception {
    public:
        /* Reception.cpp */
        Reception(float cookingTime, std::size_t nbCook, int ingredientTime, std::shared_ptr<Log> log);
        ~Reception();

        std::size_t getNbCooks() const;
        float getCookingTime() const;
        int getIngredientTime() const;

        void displayStatus() const;

        void analyseOrder(std::string const &data);

        /* setOrder.cpp */
        PizzaType getType(std::string const &type) const;
        PizzaSize getSize(std::string const &str) const;
        std::size_t getNumber(std::string const &str) const;
        void setOrders(std::vector<std::string> const &commands);

        /* orderDistribution.cpp */
        void orderDistribution(std::vector<Order> const &orderList);
        void addKitchen();

    protected:
    private:
        float _cookingTime;
        std::size_t _nbCooks;
        int _ingredientTime;

        std::shared_ptr<Log> _log;

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

        enum class Chanel {
            Write,
            Read
        };
        std::size_t _kitchenIndex;
        std::map<std::size_t, std::unordered_map<Chanel, std::shared_ptr<IPC>>> _kitchenCom;
};

#endif /* !RECEPTION_HPP_ */
