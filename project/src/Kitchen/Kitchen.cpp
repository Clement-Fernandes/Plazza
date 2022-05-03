/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#include "Error.hpp"
#include "Kitchen.hpp"

Kitchen::Kitchen(int id, float cookingTime, size_t nbCooks, int ingredientTime, IPC writer, IPC reader) :
    _id(id), _cookingTime(cookingTime), _nbCooks(nbCooks), _ingredientTime(ingredientTime), _writer(writer), _reader(reader)
{
    std::cout << "Constructor Kitchen" << std::endl;
    _stop = false;
}

Kitchen::~Kitchen()
{
}

void Kitchen::loop()
{
    while (!_stop) {
        std::string message;
        _reader >> message;
        if (handleMessage(message))
            continue;
        if (keep > 0) {
            keep--;
            _writer << "y";
        } else
            _writer << "n";
    }
}

bool Kitchen::handleMessage(std::string const &message)
{
    if (message == "exit") {
        _stop = true;
        return true;
    } if (message == "s") {
        displayStatus();
        return true;
    }
    return false;
}

void Kitchen::displayStatus(void)
{
    std::cout << "Kitchen " << _id << std::endl;
    for (auto i : _orderList) {
        std::cout << i.getName() << std::endl;
    }
}
