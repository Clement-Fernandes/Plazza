/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Fridge
*/

#ifndef FRIDGE_HPP_
    #define FRIDGE_HPP_

    #include <vector>
    #include <map>
    #include "enum.hpp"
    #include "Clock.hpp"

#include <iostream>

class Fridge {
    public:
        Fridge(int ingredientTime);
        Fridge() {
            std::cout << "construct fridge with end" << std::endl;
        };
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void printDebug() const;
        bool refillIngredients();
        bool checkRefill(long long int first, long long int second);
        void printStatus() const;

    protected:
    private:
        bool hasIngredients(std::vector<Ingredients> const &ingredientsList);
        int _ingredientTime;
        bool _running;
        std::map<Ingredients, std::size_t> _allIngredients;

        /* Clock */
        Clock _clock;
};

#endif /* !FRIDGE_HPP_ */
