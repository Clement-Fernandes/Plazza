/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Fridge
*/

#include "Error.hpp"
#include "Clock.hpp"
#include "Fridge.hpp"

#define DEFAULT_TIME -1

Fridge::Fridge(float cookingTime) : _cookingTime(cookingTime)
{
    _allIngredients = {
        {Ingredients::DOE, _cookingTime},
        {Ingredients::TOMATOE, _cookingTime},
        {Ingredients::GRUYERE, _cookingTime},
        {Ingredients::HAM, _cookingTime},
        {Ingredients::MUSHROOMS, _cookingTime},
        {Ingredients::STEAK, _cookingTime},
        {Ingredients::EGGPLANT, _cookingTime},
        {Ingredients::GOATCHEESE, _cookingTime},
        {Ingredients::CHIEFLOVE, _cookingTime}
    };
    _timer = {
        {Ingredients::DOE, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::TOMATOE, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::GRUYERE, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::HAM, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::MUSHROOMS, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::STEAK, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::EGGPLANT, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::GOATCHEESE, {DEFAULT_TIME, DEFAULT_TIME}},
        {Ingredients::CHIEFLOVE, {DEFAULT_TIME, DEFAULT_TIME}}
    };
    _running = true;
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


bool Fridge::checkRefill(long long int first, long long int second)
{
    if (second - first > _cookingTime)
        return (true);
    return (false);
}

void Fridge::refillIngredients()
{
    Clock clock;

    while (_running) {
        for (auto i : _allIngredients)
            if (i.second < _cookingTime && _timer.at(i.first).first != DEFAULT_TIME)
                _timer.at(i.first).first = clock.getElapsedTime();
        for (auto i : _timer)
            if (i.second.first != DEFAULT_TIME) {
                i.second.second = clock.getElapsedTime();
                if (checkRefill(i.second.first, i.second.second)) {
                    _allIngredients.at(i.first) += 1;
                    _timer.at(i.first).first = DEFAULT_TIME;
                    _timer.at(i.first).second = DEFAULT_TIME;
                }
            }
    }
}

void Fridge::printDebug() const
{
    int n = 0;

    for (auto i : _allIngredients) {
        std::cout << n << ": " << i.second << std::endl;
        n += 1;
    }
}
