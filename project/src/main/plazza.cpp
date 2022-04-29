/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#include "plazza.hpp"
#include "Reception.hpp"

int plazza(std::vector<std::string> const &av)
{
    Reception reception(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));

    printf("Welcome to the Plazza!\n");
    reception.terminalReader();
    return 0;
}