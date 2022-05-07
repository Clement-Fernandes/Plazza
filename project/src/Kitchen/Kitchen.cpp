/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#include <queue>
#include <unistd.h>
#include "Error.hpp"
#include "Kitchen.hpp"

// Kitchen::Kitchen(std::size_t id, float cookingTime, std::size_t nbCooks, int ingredientTime, IPC writer, IPC reader) :
Kitchen::Kitchen(std::size_t id, float cookingTime, std::size_t nbCooks, int ingredientTime, std::shared_ptr<IPC> writer, std::shared_ptr<IPC> reader) :
_id(id), _cookingTime(cookingTime), _nbCooks(nbCooks),
_ingredientTime(ingredientTime), _writer(writer), _reader(reader), _fridge(Fridge(cookingTime))
{
    // std::cout << "Constructor Kitchen" << std::endl;
    _threadPool.start(nbCooks);
    _isRunning = true;
}

Kitchen::~Kitchen()
{
    _threadPool.Stop();
    std::cout << "Kitchen " << _id << " closed !" << std::endl;
}

void Kitchen::loop()
{
    std::map<PizzaType, std::function<void ()>> bakeFunction;

    while (_isRunning) {
        *_reader >> _message;

        if (_message.compare("exit") == 0)
            _isRunning = false;
        else if (_message.compare("status") == 0)
            displayStatus();
        else if (_orderList.size() >= _nbCooks * 2)
            *_writer << "n";
        else {
            std::string::size_type pos = _message.find(' ');
            PizzaType type = static_cast<PizzaType>(std::stoi(_message.substr(0, pos)));
            PizzaSize size = static_cast<PizzaSize>(std::stoi(_message.substr(pos + 1)));

            //voir plus tard pour récupérer l'id de la commande
            _orderList.push({0, type, size});
            _threadPool.QueueJob(_orderList.front());//cookPizza,
            *_writer << "y";
        }
    }
}

void Kitchen::displayStatus(void)
{
    std::cout << "Kitchen " << _id << std::endl;
}
