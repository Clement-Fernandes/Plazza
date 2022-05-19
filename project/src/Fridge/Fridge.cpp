/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Fridge
*/

#include "Error.hpp"
#include "plazza.hpp"
#include "Fridge.hpp"

#define MAX_SIZE 5

Fridge::Fridge(int ingredientTime) : _ingredientTime(ingredientTime),
_allIngredients ({
        {Ingredients::DOE, MAX_SIZE},
        {Ingredients::TOMATOE, MAX_SIZE},
        {Ingredients::GRUYERE, MAX_SIZE},
        {Ingredients::HAM, MAX_SIZE},
        {Ingredients::MUSHROOMS, MAX_SIZE},
        {Ingredients::STEAK, MAX_SIZE},
        {Ingredients::EGGPLANT, MAX_SIZE},
        {Ingredients::GOATCHEESE, MAX_SIZE},
        {Ingredients::CHIEFLOVE, MAX_SIZE}
    })
{
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

// bool Fridge::checkRefill(long long int first, long long int second)
// {
//     if (second - first > _ingredientTime)
//         return (true);
//     return (false);
// }

// bool Fridge::refillIngredients()
// {
//     long long int time = _clock.getElapsedTime();
//     bool reffiled = false;

//     if (time > _ingredientTime) {
//         for (auto i: _allIngredients) {
//             std::unique_lock<std::mutex> lock(mutex);
//             {
//                 if (i.second < MAX_SIZE) {
//                     _allIngredients.at(i.first) += 1;
//                     reffiled = true;
//                 }
//             }
//         }
//         _clock.restart();
//     }
//     if (reffiled)
//         condition.notify_all();
//     return reffiled;
// }

// void Fridge::printDebug() const
// {
//     int n = 0;

//     for (auto i : _allIngredients) {
//         std::cout << n << ": " << i.second << std::endl;
//         n += 1;
//     }
// }

void Fridge::printStatus() const
{
    std::map<Ingredients, std::string> allIngredients {
        {Ingredients::CHIEFLOVE, "Chief Love"},
        {Ingredients::DOE, "Doe"},
        {Ingredients::EGGPLANT, "Eggplant"},
        {Ingredients::GOATCHEESE, "Goat Cheese"},
        {Ingredients::GRUYERE, "Gruyere"},
        {Ingredients::HAM, "Ham"},
        {Ingredients::MUSHROOMS, "Mushrooms"},
        {Ingredients::STEAK, "Steak"},
        {Ingredients::TOMATOE, "Tomatoe"},

    };

    printText("---");
    printText("Ingredients Stock:");
    for (auto ingredient: _allIngredients)
        printText("- " + allIngredients.at(ingredient.first) + ": " + std::to_string(ingredient.second));
}
