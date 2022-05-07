/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** printColored
*/

#include <iostream>
#include "plazza.hpp"

void printColored(std::string text, enum COLOR color, bool lineBreak)
{
    std::cout << "\033[1;" + std::to_string(color) + "m" << text << "\033[0m";
    if (lineBreak)
        std::cout << std::endl;
}