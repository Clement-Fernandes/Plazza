/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** terminalReader
*/

#include <iostream>
#include <regex>
#include "plazza.hpp"

void terminalReader()
{
    std::string data;
    std::vector<std::string> commandString;
    std::regex reg("[a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");

    while (true) {
        if (commandString.empty())
            commandString.clear();
        std::cout << "> ";
        std::getline(std::cin, data);
        if (std::cin.eof())
            break;
        if (data.empty())
            continue;
        if (data == "exit")
            break;
        commandString = strToWordArr(data, ';');
        for (size_t i = 0; i != commandString.size(); i++) {
            std::cout << "result: " << regex_match(commandString.at(i), reg) << std::endl;
        }
    }
}