/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Command
*/

#include "plazza.hpp"
#include "Command.hpp"

Command::Command(std::vector<std::string> const &commandLine)
{
    for (auto i = commandLine.begin(); i != commandLine.end(); i++) {
        std::vector<std::string> oneCommand = strToWordArr(*i, ' ');

    }
}

Command::~Command()
{
}

void Command::pack()
{

}

void Command::unpack()
{
    for (auto i = _userOrders.begin(); i != _userOrders.end(); i++) {
        for (size_t nb = 0; nb != i->_number; nb++)
            _orders.push_back(Order(i->_type, i->_size));
    }
}
