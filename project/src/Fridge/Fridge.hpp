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

class Fridge {
    public:
        Fridge(int ingredientTime);
        Fridge() {};
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void printDebug() const;
        void refillIngredients();
        bool checkRefill(long long int first, long long int second);

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
