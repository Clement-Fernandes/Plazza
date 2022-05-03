/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#include <thread>
#include <iostream>
#include "Cook.hpp"

#define MAX_QUEUE 2

Cook::Cook(Fridge &kitchenFridge, float cookingTime) : _kitchenFridge(kitchenFridge), _cookingTime(cookingTime)
{
    std::cout << "Constructor Cook" << std::endl;
    _bakeTime = {
        {PizzaType::Margarita, 1000},
        {PizzaType::Regina, 2000},
        {PizzaType::Americana, 2000},
        {PizzaType::Fantasia, 4000}
    };
}

Cook::~Cook()
{
    std::cout << "Destructor Cook" << std::endl;
}

int Cook::getCookingTime(PizzaType pizza)
{
    return (_bakeTime.at(pizza) * _cookingTime);
}

void Cook::cookLife(PizzaType pizza, PizzaSize size)
{
    Fridge fridge(_cookingTime);
    int cooking = 0;

    if (_pizzaList.size() == MAX_QUEUE); // check si le vecteur est bien inferieur au max de pizza pouvant etre stockées
        //(à faire) return (Pas de place disponible)
    _pizzaList.insert({pizza, size}); // stock la pizza dans le vecteur
    if (!fridge.getIngredients(_recipes.at(_pizzaList.begin()->first))); // demande au frigo s'il y a tout les ingredients de la première pizza dans le vecteur sont disponibles
        // (à faire) si reponse NEGATIVE, il refait un tour de boucle
    else
        cooking = getCookingTime(_pizzaList.begin()->first); // il va chercher le temps de cuisson de la pizza
    // (à faire) il cuit la pizza
    // (à faire) il communique avec la cuisine pour lui informer que la pizza est cuite
    _pizzaList.erase(_pizzaList.begin()); // il supprime la pizza du vecteur pour passer à la suivante
    // (à faire) il refait un tour de boucle


}