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

void cookPizza(Order const &order)
{
    std::cout << "type: " << order.getType() << ", size: " << order.getSize() << std::endl;
}

Kitchen::Kitchen(std::size_t id, float cookingTime, std::size_t nbCooks, int ingredientTime, IPC writer, IPC reader) :
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
}

void Kitchen::loop()
{
    std::map<PizzaType, std::function<void ()>> bakeFunction;

    while (_isRunning) {
        _reader >> _message;

        if (_message.compare("exit") == 0)
            _isRunning = false;
        else if (_message.compare("status") == 0) {
            displayStatus();
        } else if (_orderList.size() >= _nbCooks * 2)
            _writer << "n";
        else {
            std::string::size_type pos = _message.find(' ');
            PizzaType type = (PizzaType) std::stoi(_message.substr(0, pos));
            PizzaSize size = (PizzaSize) std::stoi(_message.substr(pos + 1));

            _orderList.push({type, size});
            _threadPool.QueueJob(_orderList.front());//cookPizza, 
            _writer << "y";
        }
    }
    std::cout << "Kitchen " << _id << " closed !" << std::endl;
}

bool Kitchen::handleMessage(void)
{
    if (_message == "exit") {
        _isRunning = false;
        return true;
    } if (_message == "s") {
        displayStatus();
        return true;
    }
    return false;
}

void Kitchen::displayStatus(void)
{
    std::cout << "Kitchen " << _id << std::endl;
}
