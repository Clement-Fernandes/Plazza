/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** orderDistribution
*/

#include "Process.hpp"
#include "Reception.hpp"

void Reception::addKitchen(std::size_t id)
{
    std::shared_ptr<IPC> comReception = std::make_shared<IPC>();
    std::shared_ptr<IPC> comKitchen = std::make_shared<IPC>();
    Process newProcess(1);

    _allProcesses.push_back(newProcess);
    if (newProcess.getPid() == 0) {
        Kitchen kitchen(id, _cookingTime, _nbCooks, _ingredientTime, comKitchen, comReception);

        kitchen.loop();
        kitchen.~Kitchen();
        exit(0);
    } else {
        std::unordered_map<std::string, std::shared_ptr<IPC>> info;

        info["read"] = comKitchen;
        info["write"] = comReception;
        _listKitchen.push_back(info);
    }
}

void Reception::orderDistribution(std::vector<Order> const &orderList)
{
    std::size_t kitchenId;
    std::string response;

    for (auto i = orderList.begin(); i != orderList.end();) {
        std::cout << "i" << std::endl;
        bool messageGot = false;

        for (kitchenId = 0; kitchenId < _listKitchen.size() ; kitchenId++) {
            std::string pizza = std::to_string(i->getOrderNb()) + " " + \
            std::to_string(i->getType()) + " " + std::to_string(i->getSize());
            bool readed = false;

            *_listKitchen[kitchenId]["write"] << pizza;
            std::cout << "writed" << std::endl;
            while (!readed) {
                try {
                    *_listKitchen[kitchenId]["read"] >> response;
                    std::cout << "readed" << std::endl;
                    readed = true;
                    if (response.at(0) == 'y')
                        messageGot = true;
                } catch (Error::IPC const &) {}
            }
            if (messageGot == true)
                break;
        }
        if (kitchenId == _listKitchen.size())
            addKitchen(kitchenId);
        else
            i++;
    }
}
