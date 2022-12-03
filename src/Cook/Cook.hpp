/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

    #include <memory>
    #include "Fridge.hpp"
    #include "Order.hpp"

class Cook {
    public:
        Cook(float cookingTime, std::shared_ptr<Fridge> kitchenFridge);
        ~Cook();

        std::vector<Ingredients> getPizzaIngredients(Order const &order) const;
        int getCookingTime(Order const &order) const;

    protected:
    private:
        int _cookingTime;
        std::shared_ptr<Fridge> _kitchenFridge;
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
        std::map<PizzaType, int> _bakeTime = {
            {PizzaType::Margarita, 1000},
            {PizzaType::Regina, 2000},
            {PizzaType::Americana, 2000},
            {PizzaType::Fantasia, 4000}
        };
};

#endif /* !COOK_HPP_ */
