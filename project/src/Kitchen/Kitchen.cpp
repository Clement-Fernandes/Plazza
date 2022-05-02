/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#include "Error.hpp"
#include "Kitchen.hpp"
// #include "IPC.hpp"

// Kitchen::Kitchen(float cookingTime, size_t nbCooks, int ingredientTime, int writer, int reader) :
Kitchen::Kitchen(float cookingTime, size_t nbCooks, int ingredientTime, IPC writer, IPC reader) :
    _cookingTime(cookingTime), _nbCooks(nbCooks), _ingredientTime(ingredientTime), _writer(writer), _reader(reader)
{
    std::cout << "Constructor Kitchen" << std::endl;
}

Kitchen::~Kitchen()
{
    std::cout << "Destructor Kitchen" << std::endl;
}

void Kitchen::loop()
{
    std::string message;
    _reader >> message;
    std::cout << "message recieve: " << message << std::endl;
    _writer << message;
}
