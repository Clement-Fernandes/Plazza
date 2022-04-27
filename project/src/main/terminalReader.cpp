/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** terminalReader
*/

#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "plazza.hpp"

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

struct Command {
    enum PizzaSize _size;
    enum PizzaType _type;
    int _nb;
};


static bool checkType(std::string const &str)
{
    for (size_t i = 0; i != str.size(); i++)
        if (!isalpha(str.at(i))) {
            std::cout << str.at(i) << " is not a letter" << std::endl;
            return false;
        }
    return true;
}

static bool checkSize(std::string const &str)
{
    std::vector<std::string> sizes = {"S", "M", "L", "XL", "XXL"};

    for (size_t i = 0; i != sizes.size(); i++)
        if (str == sizes.at(i))
            return true;
    std::cout << "size " << str << " doesn't exist" << std::endl;
    return false;
}

static bool checkNumber(std::string const &str)
{
    if (str.at(0) != 'x') {
        std::cout << "the format is x[1...9][0...9]" << std::endl;
        return false;
    }
    if (str.size() > 3 || str.size() < 2) {
        std::cout << "the format is x[1...9][0...9]" << std::endl;
        return false;
    }
    for (size_t i = 1; i != str.size(); i++)
        if (!isdigit(str.at(i))) {
            std::cout << "the format is x[1...9][0...9]" << std::endl;
            return false;
        }
    return true;
}

void terminalReader()
{
    std::string data;
    std::vector<std::string> commandString;

    while (true) {
        if (commandString.empty())
            commandString.clear();
        std::cout << "> ";
        std::getline(std::cin, data);
        if (std::cin.eof())
            break;
        if (data.empty())
            continue;
        commandString = strToWordArr(data, ';');
        for (size_t i = 0; i != commandString.size(); i++) {
            std::vector<std::string> splited = strToWordArr(commandString.at(i), ' ');
            if (splited.size() != 3) {
                std::cout << "invalid command" << std::endl;
                continue;
            }
            if (!checkType(splited.at(0)) ||
            !checkSize(splited.at(1)) || !checkNumber(splited.at(2)))
                continue;
        }
    }
}