/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

    #include <chrono>
    #include "Fridge.hpp"

class Cook {
    public:
        Cook(Fridge &kitchenFridge, float cookingTime);
        ~Cook();
        int getCookingTime(PizzaType pizza);
        void cookLife(PizzaType pizza, PizzaSize size);

    protected:
    private:
        Fridge _kitchenFridge;
        int _cookingTime;
        std::map<std::pair<PizzaType, PizzaSize>, bool> _pizzaList;
        std::map<PizzaType, int> _bakeTime;
        std::map<PizzaType, std::vector<Ingredients>> _recipes = {
            {
                PizzaType::Margarita, {
                    Ingredients::DOE,
                    Ingredients::TOMATOE,
                    Ingredients::GRUYERE
                }},
            {PizzaType::Regina, {
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