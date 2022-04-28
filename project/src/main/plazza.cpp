/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#include <vector>
#include <string>
#include "plazza.hpp"
#include "Reception.hpp"

int plazza(std::vector<std::string> const &av)
{
    Reception reception;

    printf("Welcome to the Plazza!\n");
    reception.terminalReader();
    return 0;
}