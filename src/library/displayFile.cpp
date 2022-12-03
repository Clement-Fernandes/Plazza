/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** display_file
*/

#include <iostream>
#include "plazza.hpp"

void displayFile(std::string const &filename, std::ostream &stream)
{
    stream << readFile(filename, "\n") << std::endl;
}
