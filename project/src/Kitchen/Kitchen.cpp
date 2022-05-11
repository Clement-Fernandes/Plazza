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

std::mutex fridgeMutex;
std::condition_variable fridgeCondition;

Kitchen::Kitchen(std::size_t id, float cookingTime, std::size_t nbCooks, int ingredientTime, std::shared_ptr<IPC> writer, std::shared_ptr<IPC> reader) :
_id(id), _cookingTime(cookingTime), _nbCooks(nbCooks),
_ingredientTime(ingredientTime), _writer(writer), _reader(reader),
_fridge(std::make_shared<Fridge>(Fridge(ingredientTime)))
{
    std::cout << "Constructor Kitchen" << std::endl;
    _fridgeThread = std::thread(&Kitchen::refillIngredients, this, _fridge);
    _threadPool.start(nbCooks, _fridge, _cookingTime);
    _isRunning = true;
    _clock.start();
    std::cout << "constructed" << std::endl;
}

Kitchen::~Kitchen()
{
    _threadPool.Stop();
    std::cout << "Kitchen " << _id << " closed!" << std::endl;
}

void Kitchen::refillIngredients(std::shared_ptr<Fridge> fridge)
{
    std::cout << "fridge" << std::endl;
    while (_isRunning) {
        {
            if (fridge->refillIngredients())
                fridgeCondition.notify_all();
        }
    }
}

void Kitchen::loop()
{
    std::map<PizzaType, std::function<void ()>> bakeFunction;

    while (_isRunning) {
        *_reader >> _message;
        std::cout << "message" << _message << std::endl;

        if (_message.compare("exit") == 0)
            _isRunning = false;
        else if (_message.compare("status") == 0)
            displayStatus();
        else if (_orderList.size() >= _nbCooks * 2)
            *_writer << "n";
        else {
            printText("yes");
            std::vector<std::string> args = strToWordArr(_message, ' ');
            size_t orderNb = std::stoi(args[0]);
            PizzaType type = static_cast<PizzaType>(std::stoi(args[1]));
            PizzaSize size = static_cast<PizzaSize>(std::stoi(args[2]));

            _orderList.push({orderNb, type, size});
            _threadPool.QueueJob(_orderList.front()); //cookPizza,
            _orderList.pop();
            *_writer << "y";
        }
        std::cout << "sortie" << std::endl;
    }
}

void Kitchen::displayStatus(void)
{
    printText("Kitchen n°" + std::to_string(_id)  + ": (running for " + std::to_string(_clock.getElapsedTime(true)) + "s)");
    _fridge->printStatus();
}
