/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#include <regex>
#include <sys/types.h>
#include <unistd.h>
#include "plazza.hpp"
#include "Error.hpp"
#include "Reception.hpp"

Reception::Reception(float cookingTime, std::size_t nbCook, int ingredientTime) : _cookingTime(cookingTime), _nbCooks(nbCook), _ingredientTime(ingredientTime)
{
    printText("Constructor Reception");
}

Reception::~Reception()
{
    std::cout << "Destructor Reception" << std::endl;
    std::cout << _listKitchen.size() << std::endl;
    for (std::size_t i = 0; i < _listKitchen.size(); i++)
        *_listKitchen.at(i)["write"] << "exit";
}

std::size_t Reception::getNbCooks() const
{
    return _nbCooks;
}

float Reception::getCookingTime() const
{
    return _cookingTime;
}

int Reception::getIngredientTime() const
{
    return _ingredientTime;
}

void Reception::displayStatus()
{
    printText("Status of Plazza", COLOR::BLUE);
    printText("Orders placed: " + std::to_string(_orderNb) + " order(s)");
    printText("Cooks: " + std::to_string(_nbCooks) + " cook(s) per kitchen");
    printText("------------------------------------------------------");

    for (std::size_t i = 0; i < _listKitchen.size(); i++)
        *_listKitchen[i]["write"] << "status";
}

void Reception::analyseOrder(std::string const &data)
{
    std::vector<std::string> commandString = strToWordArr(data, ';');
    std::regex reg("[a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");

    try {
        for (auto &i : commandString) {
            if (i[0] == ' ')
                i.erase(0, 1);
            if (!regex_match(i, reg))
                throw Error::Order("Invalid command. Format is: [a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*", true);
        }
        setOrders(commandString);
    } catch (Error::Order const &e) {
        std::cout << e.what() << std::endl;
    }
}


void Reception::printDebug() const
{
    printText("Display list kitchen :");
    // for (auto i : _listKitchen) {
        // std::cout << i.begin()->first << std::endl;
    // }
}
