/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#include <iostream>
#include "Cook.hpp"

Cook::Cook(Fridge &kitchenFridge) : _kitchenFridge(kitchenFridge)
{
    std::cout << "Constructor Cook" << std::endl;
}

Cook::~Cook()
{
    std::cout << "Destructor Cook" << std::endl;
}
