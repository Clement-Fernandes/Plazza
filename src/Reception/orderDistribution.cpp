/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** orderDistribution
*/

#include "Error.hpp"
#include "Kitchen.hpp"
#include "plazza.hpp"
#include "Reception.hpp"

void Reception::addKitchen()
{
    std::shared_ptr<IPC> comReception = std::make_shared<IPC>();
    std::shared_ptr<IPC> comKitchen = std::make_shared<IPC>();
    std::unordered_map<Chanel, std::shared_ptr<IPC>> info;
    info.insert({Chanel::Read, comKitchen});
    info.insert({Chanel::Write, comReception});

    _kitchenCom.insert({_kitchenIndex, info});

    Process newProcess;
    if (newProcess.getPid() == 0) {
        std::size_t id;
        {
            Kitchen kitchen(_kitchenIndex, _log, _cookingTime, _nbCooks, _ingredientTime, comKitchen, comReception);
            id = kitchen.loop();
        }
        _kitchenCom.erase(id);
        exit(0);
    }
    _kitchenIndex++;
}

void Reception::orderDistribution(std::vector<Order> const &orderList)
{

    for (auto i = orderList.begin(); i != orderList.end();) {
        std::string response;
        bool orderAccepted = false;
        for (auto &[kitchenId, kitchenCom] : _kitchenCom) {
            std::string pizza = std::to_string(i->getOrderNb()) + " " + \
            std::to_string(i->getType()) + " " + std::to_string(i->getSize());

            *_log << "Reception asked to kitchen " + std::to_string(kitchenId) + " if she could take an order";
            *kitchenCom[Chanel::Write] << pizza;
            try {
                *kitchenCom[Chanel::Read] >> response;
                if (response.at(0) == 'y') {
                    orderAccepted = true;
                }
            } catch (Error::IPC const &) {}
            if (orderAccepted)
                break;
        }
        if (!orderAccepted)
            addKitchen();
        else
            i++;
    }
}
