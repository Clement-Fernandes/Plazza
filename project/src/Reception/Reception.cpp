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

Reception::Reception(float cookingTime, size_t nbCook, int ingredientTime) : _cookingTime(cookingTime), _nbCooks(nbCook), _ingredientTime(ingredientTime)
{
    std::cout << "Constructor Reception" << std::endl;
}

Reception::~Reception()
{
    std::cout << "Destructor Reception" << std::endl;
}

void Reception::closeKitchen()
{
    for (size_t i = 0; i < _listKitchen.size(); i++)
        _listKitchen[i]["write"] << "exit";
    for (auto kitchen : _listKitchen)
        kitchen["write"] << "s";
}

void Reception::exitPlazza(void)
{
    for (auto kitchen : _listKitchen) {
        kitchen["write"] << "exit";
    }
    _isRunning = false;
}

// bool Reception::handleSpecialRequest(std::string const &data)
// {
//     if (std::cin.eof()) {
//         exitPlazza();
//         return true;
//     } if (data.empty())
//         return true;
//     if (data == "exit") {
//         exitPlazza();
//         return true;
//     }
//     if (data == "status") {
//         displayStatus();
//         return true;
//     }
//     return false;
// }

void Reception::analyseOrder(std::string const &data)
{
    std::vector<std::string> commandString = strToWordArr(data, ';');;
    std::regex reg("[a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");

    try {
        for (auto &i : commandString) {
            if (regex_match(i, reg))
                setOrders(strToWordArr(data, ';'));
            else
                throw Error::Order("Invalid command. Format is: [a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");
        }
    } catch (Error::Order const &e) {
        std::cout << e.what() << std::endl;
    }
}

size_t Reception::getNbCooks() const
{
    return _nbCooks;
}

float Reception::getCookingTime() const
{
    return _cookingTime;
}

void Reception::printDebug() const
{
    std::cout << "Display list kitchen :" << std::endl;
    for (auto i : _listKitchen) {
        std::cout << i.begin()->first << std::endl;
    }
}
