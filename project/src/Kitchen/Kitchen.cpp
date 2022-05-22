/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#include "plazza.hpp"
#include "Kitchen.hpp"

Kitchen::Kitchen(std::size_t id, std::shared_ptr<Log> log, float cookingTime, std::size_t nbCooks, int ingredientTime, std::shared_ptr<IPC> writer, std::shared_ptr<IPC> reader) :
 _id(id), _log(log), _cookingTime(cookingTime), _nbCooks(nbCooks), _ingredientTime(ingredientTime),
 _writer(writer), _reader(reader), _isRunning(true),
 _fridge(std::make_shared<Fridge>(ingredientTime)), _fridgeThread(&Kitchen::refillIngredients, this),
 _threadPool(_log, _nbCooks, _cookingTime, _fridge)
{
    _clock.start();
    *_log << "Kitchen " + std::to_string(_id) + " opened";
}

Kitchen::~Kitchen()
{
    _threadPool.stop();
    _fridgeThread.join();
    *_log << "Kitchen " + std::to_string(_id) + " closed";
}

std::size_t Kitchen::loop()
{
    std::string message;

    while (_isRunning) {
        message.clear();
        *_reader >> message;
        if (message.compare("exit") == 0)
            _isRunning = false;
        else if (message.compare("status") == 0) {
            displayStatus();
            *_writer << "finish";
        } else if (_threadPool.getQueueSize() >= _nbCooks) {
            *_log << "Kitchen " + std::to_string(_id) + " refused the order";
            *_writer << "n";
        } else {
            std::vector<std::string> args = strToWordArr(message, ' ');
            size_t orderNb = std::stoi(args[0]);
            PizzaType type = static_cast<PizzaType>(std::stoi(args[1]));
            PizzaSize size = static_cast<PizzaSize>(std::stoi(args[2]));

            *_log << "Kitchen " + std::to_string(_id) + " accepted the order";
            *_writer << "y";
            _threadPool.queueJob({orderNb, type, size});
        }
    }
    return _id;
}

void Kitchen::refillIngredients()
{
    while (_isRunning)
        _fridge->refillIngredients();
}

void Kitchen::displayStatus()
{
    *_log << "Status of kitchen " + std::to_string(_id);
    printText("Kitchen n°" + std::to_string(_id)  + ": (running for " + std::to_string(_clock.getElapsedTime(true)) + "s)");
    _fridge->printStatus();
}
