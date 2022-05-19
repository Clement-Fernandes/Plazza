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
_fridge(std::make_shared<Fridge>(ingredientTime)), _threadPool(_log, _nbCooks, _cookingTime, _fridge)
{
    _clock.start();
    *_log << "Kitchen " + std::to_string(_id) + " opened";
    // _fridgeThread = std::thread(&Kitchen::refillIngredients, this, _fridge);
}

Kitchen::~Kitchen()
{
    _threadPool.stop();
    *_log << "Kitchen " + std::to_string(_id) + " closed";
}

/*void Kitchen::refillIngredients(std::shared_ptr<Fridge> fridge)
{
    while (_isRunning) {
        {
            if (fridge->refillIngredients())
                fridge->condition.notify_all();
        }
    }
}*/

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
        } else if (_orderList.size() >= _nbCooks * 2) {
            *_log << "Kitchen " + std::to_string(_id) + " refused the order";
            *_writer << "n";
        } else {
            std::vector<std::string> args = strToWordArr(message, ' ');
            size_t orderNb = std::stoi(args[0]);
            PizzaType type = static_cast<PizzaType>(std::stoi(args[1]));
            PizzaSize size = static_cast<PizzaSize>(std::stoi(args[2]));

            _orderList.push({orderNb, type, size});
            *_log << "Kitchen " + std::to_string(_id) + " accepted the order";
            *_writer << "y";
            _threadPool.queueJob(_orderList.front());
            _orderList.pop();
        }
    }
    return _id;
}

void Kitchen::displayStatus(void)
{
    *_log << "Status of kitchen " + std::to_string(_id);
    printText("Kitchen n°" + std::to_string(_id)  + ": (running for " + std::to_string(_clock.getElapsedTime(true)) + "s)");
    _fridge->printStatus();
}
