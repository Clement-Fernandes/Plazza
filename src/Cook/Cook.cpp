/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#include "Cook.hpp"

Cook::Cook(float cookingTime, std::shared_ptr<Fridge> kitchenFridge)
 : _cookingTime(cookingTime), _kitchenFridge(kitchenFridge)
{
}

Cook::~Cook()
{
}

std::vector<Ingredients> Cook::getPizzaIngredients(Order const &order) const
{
    return _recipes.at(order.getType());
}

int Cook::getCookingTime(Order const &order) const
{
    return _bakeTime.at(order.getType()) * _cookingTime;
}
