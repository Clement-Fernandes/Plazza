/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Fridge
*/

#include "Error.hpp"
#include "Fridge.hpp"

Fridge::Fridge()
{
    _allIngredients = {
        {Ingredients::DOE, 5},
        {Ingredients::TOMATOE, 5},
        {Ingredients::GRUYERE, 5},
        {Ingredients::HAM, 5},
        {Ingredients::MUSHROOMS, 5},
        {Ingredients::STEAK, 5},
        {Ingredients::EGGPLANT, 5},
        {Ingredients::GOATCHEESE, 5},
        {Ingredients::CHIEFLOVE, 5}
    };
}

Fridge::~Fridge()
{
}

bool Fridge::getIngredients(std::vector<Ingredients> const &ingredientsList)
{
    if (!hasIngredients(ingredientsList))
        return false;

    for (auto i : ingredientsList)
        _allIngredients.at(i) -= 1;
    return true;
}

bool Fridge::hasIngredients(std::vector<Ingredients> const &ingredientsList)
{
    for (auto i : ingredientsList) {
        try {
            if (_allIngredients.at(i) <= 0)
                return false;
        } catch (std::out_of_range const &) {
            throw Error::Fridge("Ingredient doesn't exist!");
        };
    }
    return true;
}

void Fridge::printDebug() const
{
    int n = 0;

    for (auto i : _allIngredients) {
        std::cout << n << ": " << i.second << std::endl;
        n += 1;
    }
}
