/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#include "Error.hpp"
#include "Kitchen.hpp"

Kitchen::Kitchen(float cookingTime, size_t nbCooks, int ingredientTime, IPC writer, IPC reader) :
    _cookingTime(cookingTime), _nbCooks(nbCooks), _ingredientTime(ingredientTime), _writer(writer), _reader(reader), _fridge(Fridge(cookingTime))
{
    // std::cout << "Constructor Kitchen" << std::endl;
    _isRunning = true;
}

Kitchen::~Kitchen()
{
}

void Kitchen::loop()
{
    while (_isRunning) {
        _reader >> _message;

        if (_message.compare("exit") == 0)
            _isRunning = false;
        else if (_orderList.size() >= _nbCooks * 2) {
            _writer << "n";
        } else {
            std::string::size_type pos = _message.find(' ');
            PizzaType type = (PizzaType) std::stoi(_message.substr(0, pos));
            PizzaSize size = (PizzaSize) std::stoi(_message.substr(pos + 1));
            _orderList.push_back({type, size});
            _writer << "y";
        }
    }
}
