/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Reception
*/

#include <regex>
#include "Error.hpp"
#include "plazza.hpp"
#include "Reception.hpp"

Reception::Reception()
{
}

Reception::~Reception()
{
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
        }
    }
}
