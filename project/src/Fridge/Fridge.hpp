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

class Fridge {
    public:
        Fridge(float cookingTime);
        Fridge() {};
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void printDebug() const;
        void refillIngredients();
        bool checkRefill(long long int first, long long int second);

    protected:
    private:
        bool hasIngredients(std::vector<Ingredients> const &ingredientsList);
        float _cookingTime;
        bool _running;
        std::map<Ingredients, std::size_t> _allIngredients;
        std::map<Ingredients, std::pair<long long int, long long int>> _timer;
};

#endif /* !FRIDGE_HPP_ */
