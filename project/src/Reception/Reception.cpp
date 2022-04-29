/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#include <iostream>
#include <regex>
#include <sys/types.h>
#include <unistd.h>
#include "plazza.hpp"
#include "Reception.hpp"

Reception::Reception()
{
    std::cout << "Constructor Reception" << std::endl;
    _nbCooks = 2;
    _cookingTime = 2000;
}

Reception::~Reception()
{
    std::cout << "Destructor Reception" << std::endl;
}

void Reception::actionKitchen()
{
    int a[2];
    int b[2];
    pid_t pid = fork();

    if (pipe(a) == -1 || pipe(b) == -1)
        throw Error::Error("Pipe failed!");
    if (pid == 0) {
        Kitchen kitchen;

        kitchen.loop();
        exit(0);
    } else if (pid > 0) {
        std::unordered_map<std::string, int> info;

        info["read"] = a[0];
        info["write"] = b[1];
        _listKitchen.push_back(info);
        // printDebug();
    } else
        throw Error::Error("fork failed!");
}

void Reception::orderDistribution()
{
    // if create kitchen : actionKitchen()
    actionKitchen();
}

void Reception::terminalReader()
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
            if (regex_match(commandString.at(i), reg))
                orderDistribution();
        }
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
