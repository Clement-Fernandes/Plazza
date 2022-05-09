/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#include <iostream>
#include "Clock.hpp"
#include "Cook.hpp"

#define MAX_QUEUE 2
extern std::mutex fridgeMutex;
extern std::condition_variable fridgeconditionalVariable;

Cook::Cook(std::shared_ptr<Fridge> kitchenFridge, float cookingTime)
 : _kitchenFridge(kitchenFridge), _cookingTime(cookingTime)
{
    std::cout << "Constructor Cook" << std::endl;
    _cookingPizza = 0;
    _inactiveTime = 0;
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

void Cook::checkActivity(void)
{
    Clock clock;

    if (_pizzaList.empty() || _cookingPizza > 0) {
        _inactiveTime = clock.getElapsedTime();
        if (_inactiveTime > 5)
            _active = false;
    } else {
        _inactiveTime = 0;
        _active = true;
    }
}

void Cook::cookLife(PizzaType pizza, PizzaSize size)
{
    //if (_pizzaList.size() == MAX_QUEUE) // check si le vecteur est bien inferieur au max de pizza pouvant etre stockées
        //(à faire) return (Pas de place disponible)
    checkActivity(); // check si le cuisinier est entrain de travailler
    _pizzaList.insert({{pizza, size}, false}); // stock la pizza dans le vecteur
    if (!_kitchenFridge->getIngredients(_recipes.at(_pizzaList.begin()->first.first))); // demande au frigo s'il y a tout les ingredients de la première pizza dans le vecteur sont disponibles
        // (à faire) si reponse NEGATIVE, il refait un tour de boucle
    else
        _cookingPizza = getCookingTime(_pizzaList.begin()->first.first); // il va chercher le temps de cuisson de la pizza
    // (à faire) il cuit la pizza
    _pizzaList.begin()->second = true; // (à faire) il communique avec la cuisine pour lui informer que la pizza est cuite
    _pizzaList.erase(_pizzaList.begin()); // il supprime la pizza du vecteur pour passer à la suivante
    // (à faire) il refait un tour de boucle
}

void Cook::cookPizza(Order const &order)
{
    std::cout << "type: " << order.getType() << ", size: " << order.getSize() << std::endl;
    if (!_kitchenFridge->getIngredients({Ingredients::DOE})) {
        {
            std::unique_lock<std::mutex> lock(fridgeMutex);
            fridgeconditionalVariable.wait(lock, [this] {
                return _kitchenFridge->getIngredients({Ingredients::DOE});
            });
        }
    }
    _kitchenFridge->printDebug();
}
