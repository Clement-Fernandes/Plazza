/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#include <iostream>
#include "Clock.hpp"
#include "Cook.hpp"

#define MAX_QUEUE 2
extern std::condition_variable fridgeConditionalVariable;

Cook::Cook(std::shared_ptr<Fridge> kitchenFridge, float cookingTime)
 : _kitchenFridge(kitchenFridge), _cookingTime(cookingTime)
{
    std::cout << "Constructor Cook" << std::endl;
    _cookingPizza = 0;
    _inactiveTime = 0;
    _bakeTime = {
        {PizzaType::Margarita, 1000},
        {PizzaType::Regina, 2000},
        {PizzaType::Americana, 2000},
        {PizzaType::Fantasia, 4000}
    };
}

Cook::~Cook()
{
    std::cout << "Destructor Cook" << std::endl;
}

std::vector<Ingredients> Cook::getPizzaIngredients(Order const &order) const
{
    return _recipes.at(order.getType());
}

int Cook::getCookingTime(PizzaType pizza)
{
    return (_bakeTime.at(pizza) * _cookingTime);
}

void Cook::checkActivity(void)
{
    Clock clock;

    if (_pizzaList.empty() || _cookingPizza > 0) {
        _inactiveTime = clock.getElapsedTime();
        if (_inactiveTime > 5)
            _active = false;
    } else {
        _inactiveTime = 0;
        _active = true;
    }
}

