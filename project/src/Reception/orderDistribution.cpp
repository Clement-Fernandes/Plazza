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
    // std::cout << "Create new Kitchen" << std::endl;
    IPC comReception;
    IPC comKitchen;

    Process newProcess(1);
    _allProcesses.push_back(newProcess);
    if (newProcess.getPid() == 0) {
        Kitchen kitchen(0, _cookingTime, _nbCooks, _ingredientTime, comKitchen, comReception);
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
    // int it = 0;

    for (auto i = orderList.begin(); i != orderList.end(); kitchenId++) {
        bool messageGot = false;
        // std::cout << "Iteration : " << it << ", Pizza type : " << i->getType() << std::endl;

        for (kitchenId = 0; kitchenId < _listKitchen.size(); kitchenId++) {
            std::string pizza = std::to_string(i->getType()) + " " + std::to_string(i->getSize());
            bool readed = false;

            _listKitchen[kitchenId]["write"] << pizza;

            while (!readed) {
                try {
                    _listKitchen[kitchenId]["read"] >> response;
                    readed = true;
                    if (response == "y") {
                        messageGot = true;
                    }
                } catch (Error::IPC const &) {}
            }
            if (messageGot == true)
                break;
        }
        // std::cout << "kitchenID : " << kitchenId << std::endl;
        if (kitchenId == _listKitchen.size())
            addKitchen();
        else {
            // std::cout << "Pizza " << it << " attribué !" << std::endl;
            // std::cout << " " << std::endl;
            // it++;
            i++;
        }
    }
}
