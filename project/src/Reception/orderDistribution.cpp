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
    IPC comReception;
    IPC comKitchen;

    Process newProcess(1);
    _allProcesses.push_back(newProcess);
    if (newProcess.getPid() == 0) {
        Kitchen kitchen(_cookingTime, _nbCooks, _ingredientTime, comKitchen, comReception);
        // _allKitchen.push_back(kitchen);

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
        for (kitchenId = 0; kitchenId < _listKitchen.size(); kitchenId++) {
            std::string str = "pizza";
            _listKitchen[kitchenId]["write"] << str;
            bool readed = false;
            while (!readed) {
                try {
                    _listKitchen[kitchenId]["read"] >> response;
                    readed = true;
                } catch (Error::IPC const &) {
                    std::cout << "catch something" << std::endl;
                    continue;
                }
            }
            std::cout << "message retrieve: " << response << std::endl;

        }
        if (kitchenId == _listKitchen.size())
            addKitchen();
        else
            i++;
    }
}
