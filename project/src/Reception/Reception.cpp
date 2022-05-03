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

Reception::Reception(float cookingTime, size_t nbCook, int ingredientTime) : _cookingTime(cookingTime), _nbCooks(nbCook), _ingredientTime(ingredientTime)
{
    std::cout << "Constructor Reception" << std::endl;
}

Reception::~Reception()
{
    std::cout << "Destructor Reception" << std::endl;
}

void Reception::displayStatus(void) const
{
    std::cout << "status" << std::endl;
}

void Reception::writeMessage(int fd, std::string const &text) const
{
    write(fd, text.c_str(), text.size());
}

int Reception::readMessage(int fd)
{
    if (read(fd, &_message, 2048) == -1)
        return (-1);
    return (0);
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
    int kitchenCom[2];
    int receptionCom[2];
    pid_t pid = fork();

    if (pipe(kitchenCom) == -1 || pipe(receptionCom) == -1)
        throw Error::Error("Pipe failed!");
    if (pid == 0) {
        Kitchen kitchen(_cookingTime, _nbCooks, _ingredientTime, kitchenCom[Com::Write], receptionCom[Com::Read]);

        kitchen.loop();
        exit(0);
    } else if (pid > 0) {
        std::unordered_map<std::string, int> info;

        info["read"] = kitchenCom[Com::Read];
        info["write"] = receptionCom[Com::Write];
        _listKitchen.push_back(info);
    } else
        throw Error::Error("fork failed!");
}

void Reception::orderDistribution(std::vector<Order> const &orderList)
{
    size_t kitchenId;
    size_t i = 0;

    while (i < orderList.size()) {

        for (kitchenId = 0; kitchenId < _listKitchen.size(); kitchenId++) {
            std::string pizza(std::to_string(orderList.at(i).getType()) + std::to_string(orderList.at(i).getSize()));

            writeMessage(_listKitchen[kitchenId]["write"], pizza);
            while (readMessage(_listKitchen[kitchenId]["read"]) == 1);

            if (this->_message[0] == 'y') {
                break;
            }
        }
        if (kitchenId == _listKitchen.size()) {
            actionKitchen();
        }
        else {
            i += 1;
        }
    }
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
                else
                    throw Error::Order("Invalid command. Format is: [a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*");
            }
        } catch (Error::Order const &e) {
            std::cout << e.what() << std::endl;
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
