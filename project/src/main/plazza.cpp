/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#include <algorithm>
#include "plazza.hpp"
#include "Reception.hpp"

#include <iostream>

static bool handleHelp(std::string const &data)
{
    bool request = false;
    std::map<std::string, std::string> helper_list {
        {"-h", "conf/runtimeHelper.conf"},
        {"--help", "conf/runtimeHelper.conf"},
        {"--size", "conf/size.conf"},
        {"--type", "conf/pizza.conf"}
    };
    std::vector<std::string> datas = strToWordArr(data, ' ');

    for (auto &[option, file] : helper_list) {
        if (std::find(datas.begin(), datas.end(), option) != datas.end()) {
            if (request)
                std::cout << std::endl;
            displayFile(file, std::cout);
            request = true;
        }
    }
    return request;
}

static bool stopPlazza(std::string const &data)
{
    if (std::cin.eof()) {
        printText("exit");
        return true;
    } if (data.empty())
        return false;
    if (data == "exit")
        return true;
    return false;
}

int plazza(std::vector<std::string> const &av)
{
    std::shared_ptr<Log> log = std::make_shared<Log>();
    Reception reception(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]), log);
    std::string data;
    bool running = true;

    printText("Welcome to the Plazza!", COLOR::BLUE);
    while (running) {
        printText("> ", COLOR::CYAN, false);
        std::getline(std::cin, data);
        if (stopPlazza(data)) {
            *log << "Client asked Plazza to 'exit'";
            running = false;
        } else if (handleHelp(data))
            *log << "Client asked 'help'";
        else if (data == "status")
            reception.displayStatus();
        else
            reception.analyseOrder(data);
    }
    return SUCCESS_EXIT;
}