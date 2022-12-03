/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#include <regex>
#include "Error.hpp"
#include "plazza.hpp"
#include "Reception.hpp"


Reception::Reception(float cookingTime, std::size_t nbCook, int ingredientTime, std::shared_ptr<Log> log) :
_cookingTime(cookingTime), _nbCooks(nbCook), _ingredientTime(ingredientTime), _log(log), _kitchenIndex(0)
{
    *_log << "Reception Opened";
}

Reception::~Reception()
{
    for (auto kitchenCom = _kitchenCom.begin(); kitchenCom != _kitchenCom.end(); kitchenCom++)
        *kitchenCom->second[Chanel::Write] << "exit";
    *_log << "Reception Closed";
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

void Reception::displayStatus() const
{
    std::string buffer;

    *_log << "Client asked the 'status'";
    printText("Status of Plazza", COLOR::BLUE);
    printText("Orders placed: " + std::to_string(_orderNb) + " order(s)");
    for (auto kitchenCom = _kitchenCom.begin(); kitchenCom != _kitchenCom.end(); kitchenCom++) {
        *kitchenCom->second.at(Chanel::Write) << "status";
        *kitchenCom->second.at(Chanel::Read) >> buffer;
    }
}

void Reception::analyseOrder(std::string const &data)
{
    std::vector<std::string> commandString = strToWordArr(data, ';');
    std::regex reg("[a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");

    *_log << "The client has ordered '" + data + "'";
    try {
        for (auto &i : commandString) {
            if (i[0] == ' ')
                i.erase(0, 1);
            if (!regex_match(i, reg)) {
                *_log << "Command '" + i + "' is invalid";
                throw Error::Order("Invalid command. Format is: [a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");
            }
        }
    } catch (Error::Order const &e) {
        printText(e.what(), COLOR::RED);
        return;
    }
    setOrders(commandString);
}

