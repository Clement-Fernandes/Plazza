/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#include <queue>
#include <iomanip>
#include <unistd.h>
#include "Error.hpp"
#include "plazza.hpp"
#include "Kitchen.hpp"

Kitchen::Kitchen(std::size_t id, float cookingTime, std::size_t nbCooks, int ingredientTime, std::shared_ptr<IPC> writer, std::shared_ptr<IPC> reader) :
_id(id), _cookingTime(cookingTime), _nbCooks(nbCooks),
_ingredientTime(ingredientTime), _writer(writer), _reader(reader), _fridge(Fridge(cookingTime))
{
    // std::cout << "Constructor Kitchen" << std::endl;
    _threadPool.start(nbCooks, std::make_shared<Fridge>(_fridge), _cookingTime);
    _isRunning = true;
    _clock.start();
}

Kitchen::~Kitchen()
{
    _threadPool.Stop();
    std::cout << "Kitchen " << _id << " closed!" << std::endl;
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
            std::vector<std::string> args = strToWordArr(_message, ' ');
            size_t orderNb = std::stoi(args[0]);
            PizzaType type = static_cast<PizzaType>(std::stoi(args[1]));
            PizzaSize size = static_cast<PizzaSize>(std::stoi(args[2]));

            _orderList.push({orderNb, type, size});
            _threadPool.QueueJob(_orderList.front());//cookPizza,
            *_writer << "y";
        }
    }
}

void Kitchen::displayStatus(void)
{
    printText("Kitchen n°" + std::to_string(_id)  + ": (running for " + std::to_string(_clock.getElapsedTime(true)) + "s)");
}
