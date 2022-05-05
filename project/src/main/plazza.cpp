/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#include <algorithm>
#include "plazza.hpp"
#include "Reception.hpp"

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
    return request;
}

static bool stopPlazza(std::string const data)
{
    if (std::cin.eof())
        return true;
    if (data.empty())
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

    std::cout << "\033[1;34mWelcome to the Plazza!\n\033[0m";
    std::cout << "\033[1;36m> \033[0m";
    while (running) {
        std::getline(std::cin, data);
        if (stopPlazza(data)) {
            running = false;
            continue;
        }
        if (handleRequest(data))
            continue;
        if (data == "status") {
            std::cout << "\033[1;34mStatus of Plazza\033[0m" << std::endl;
            std::cout << "Orders placed: " << "?" << " order(s)" << std::endl;
            std::cout <<"Cooks: " << std::stoi(av[2]) << " cook(s) per kitchen" << std::endl;
            std::cout << "------------------------------------------------------" << std::endl;
            reception.displayStatus();
        }
        else
            reception.analyseOrder(data);
        std::cout << "\033[1;36m> \033[0m";
    }
    reception.closeKitchen();
    return EXIT_SUCCESS;
}