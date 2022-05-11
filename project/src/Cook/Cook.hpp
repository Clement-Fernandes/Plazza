/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

    #include <chrono>
    #include <memory>
    #include <mutex>
    #include <condition_variable>
    #include "Fridge.hpp"
    #include "Order.hpp"

class Cook {
    public:
        Cook(std::shared_ptr<Fridge> kitchenFridge, float cookingTime);
        Cook() {};
        ~Cook();

        int getCookingTime(PizzaType pizza);
        void checkActivity(void);
        std::vector<Ingredients> getPizzaIngredients(Order const &order) const;

    protected:
    private:
        std::shared_ptr<Fridge> _kitchenFridge;
        bool _active;
        int _inactiveTime;
        int _cookingTime;
        int _cookingPizza;
        std::map<std::pair<PizzaType, PizzaSize>, bool> _pizzaList;
        // std::queue<Order> _orderList;
        std::map<PizzaType, int> _bakeTime;
        std::map<PizzaType, std::vector<Ingredients>> _recipes = {
            {
                PizzaType::Margarita, {
                    Ingredients::DOE,
                    Ingredients::TOMATOE,
                    Ingredients::GRUYERE
                }
            },
            {
                PizzaType::Regina, {
                    Ingredients::DOE,
                    Ingredients::TOMATOE,
                    Ingredients::GRUYERE,
                    Ingredients::HAM,
                    Ingredients::MUSHROOMS
                }
            },
            {
                PizzaType::Americana, {
                    Ingredients::DOE,
                    Ingredients::TOMATOE,
                    Ingredients::GRUYERE,
                    Ingredients::STEAK
                }
            },
            {
                PizzaType::Fantasia, {
                    Ingredients::DOE,
                    Ingredients::TOMATOE,
                    Ingredients::EGGPLANT,
                    Ingredients::GOATCHEESE,
                    Ingredients::CHIEFLOVE
                }
            }
        };
};

#endif /* !COOK_HPP_ */