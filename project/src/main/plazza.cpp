/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#include <algorithm>
#include "plazza.hpp"
#include "Reception.hpp"

static void displayStatus(void)
{
    std::cout << "status" << std::endl;
}

static bool handleRequest(std::string const &data)
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

static bool stopPlazza(std::string const data)
{
    if (std::cin.eof())
        return true;
    if (data == "exit")
        return true;
    return false;
}

int plazza(std::vector<std::string> const &av)
{
    Reception reception(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));
    std::string data;
    bool running = true;

    printf("Welcome to the Plazza!\n");
    while (running) {
        std::cout << "> ";
        std::getline(std::cin, data);
        if (data.empty())
            continue;
        if (stopPlazza(data)) {
            running = false;
            continue;
        }
        if (handleRequest(data))
            continue;
        reception.analyseOrder(data);
    }
    reception.closeKitchen();
    return EXIT_SUCCESS;
}