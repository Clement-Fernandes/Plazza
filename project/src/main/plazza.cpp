/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#include <algorithm>
#include "plazza.hpp"
#include "Reception.hpp"

static bool handleHelper(std::string const &data)
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
    return request;
}

static bool stopPlazza(std::string const &data)
{
    if (std::cin.eof()) {
        std::cout << "exit" << std::endl;
        return true;
    } if (data.empty())
        return false;
    if (data == "exit")
        return true;
    return false;
}

int plazza(std::vector<std::string> const &av)
{
    Reception reception(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));
    std::string data;
    bool running = true;

    printColored("Welcome to the Plazza!\n", COLOR::BLUE);
    while (running) {
        printColored("> ", COLOR::CYAN);
        std::getline(std::cin, data);
        if (stopPlazza(data)) {
            running = false;
            continue;
        }
        if (handleHelper(data))
            continue;
        if (data == "status") {
            reception.displayStatus();
        }
        else
            reception.analyseOrder(data);
    }
    return SUCCESS_EXIT;
}