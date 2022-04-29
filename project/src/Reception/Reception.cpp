/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#include <regex>
#include <sys/types.h>
#include <unistd.h>
#include "plazza.hpp"
#include "Error.hpp"
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

void Reception::displayStatus(void) const
{
    std::cout << "status" << std::endl;
}

bool Reception::handleRequest(std::string const &data) const
{
    bool request = false;
    std::map<std::string, std::string> helper_list {
        {"-h", "conf/runtimeHelper.conf"},
        {"--helper", "conf/runtimeHelper.conf"},
        {"--size", "conf/size.conf"},
        {"--type", "conf/pizza.conf"}
    };
    std::vector<std::string> datas = strToWordArr(data, ' ');

    for (auto &i : helper_list) {
        if (std::find(datas.begin(), datas.end(), i.first) != datas.end()) {
            if (request)
                std::cout << std::endl;
            displayFile(i.second, std::cout);
            request = true;
        }
    }
    if (data == "status") {
        request = true;
        displayStatus();
    }
    return request;
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
        if (handleRequest(data))
            continue;
        commandString = strToWordArr(data, ';');
        try {
            for (auto &i : commandString) {
                if (regex_match(i, reg))
                    setOrders(strToWordArr(data, ';'));
            }
        } catch (Error::Order const &e) {
            std::cout << e.what() << std::endl;
        // for (size_t i = 0; i != commandString.size(); i++) {
        //     if (regex_match(commandString.at(i), reg))
        //         orderDistribution();
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
