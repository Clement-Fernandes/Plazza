/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Fridge
*/

#include "Error.hpp"
#include "Clock.hpp"
#include "Fridge.hpp"

#define MAX_SIZE 5
#define DEFAULT_TIME -1

Fridge::Fridge(int ingredientTime) : _ingredientTime(ingredientTime)
{
    _running = true;
    _allIngredients = {
        {Ingredients::DOE, MAX_SIZE},
        {Ingredients::TOMATOE, MAX_SIZE},
        {Ingredients::GRUYERE, MAX_SIZE},
        {Ingredients::HAM, MAX_SIZE},
        {Ingredients::MUSHROOMS, MAX_SIZE},
        {Ingredients::STEAK, MAX_SIZE},
        {Ingredients::EGGPLANT, MAX_SIZE},
        {Ingredients::GOATCHEESE, MAX_SIZE},
        {Ingredients::CHIEFLOVE, MAX_SIZE}
    };
    _clock.start();

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
    if (second - first > _ingredientTime)
        return (true);
    return (false);
}

void Fridge::refillIngredients()
{
    long long int time = _clock.getElapsedTime();

    if (time > _ingredientTime) {
        for (auto i: _allIngredients) {
            if (i.second < 5)
                i.second += 1;
        }
        _clock.restart();
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
