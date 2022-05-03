/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** orderDistribution
*/

#include "Process.hpp"
#include "Reception.hpp"

void Reception::addKitchen()
{
    std::cout << "create new Kitchen" << std::endl;
    IPC comReception;
    IPC comKitchen;

    Process newProcess(1);
    _allProcesses.push_back(newProcess);
    if (newProcess.getPid() == 0) {
        Kitchen kitchen(_cookingTime, _nbCooks, _ingredientTime, comKitchen, comReception);
        kitchen.loop();
        exit(0);
    } else {
        std::unordered_map<std::string, IPC> info;

        info["read"] = comKitchen;
        info["write"] = comReception;
        _listKitchen.push_back(info);
    }
}

void Reception::orderDistribution(std::vector<Order> const &orderList)
{
    size_t kitchenId;
    std::string response;

    for (auto i = orderList.begin(); i != orderList.end();) {
        bool messageGot = false;
        for (kitchenId = 0; kitchenId < _listKitchen.size() && !messageGot; kitchenId++) {
            std::string pizza = std::to_string(i->getType()) + " " + std::to_string(i->getSize());
            bool readed = false;

            _listKitchen[kitchenId]["write"] << pizza;
            while (!readed) {
                try {
                    _listKitchen[kitchenId]["read"] >> response;
                    readed = true;
                    if (response == "yes")
                        messageGot = true;
                } catch (Error::IPC const &) {}
            }
        }
        if (kitchenId == _listKitchen.size())
            addKitchen();
        else
            i++;
    }
}
