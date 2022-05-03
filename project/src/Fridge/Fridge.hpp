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

    #define MAX_SIZE 5
    #define DEFAULT_TIME -1
class Fridge {
    public:
        Fridge();
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void printDebug() const;
        void refillIngredients();

    protected:
    private:
        bool hasIngredients(std::vector<Ingredients> const &ingredientsList);
        bool _running;
        std::map<Ingredients, size_t> _allIngredients;
        std::map<Ingredients, std::pair<long long int, long long int>> _timer;
};

#endif /* !FRIDGE_HPP_ */
