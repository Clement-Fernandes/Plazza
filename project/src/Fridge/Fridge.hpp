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
        Fridge();
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void printDebug() const;

    protected:
    private:
        bool hasIngredients(std::vector<Ingredients> const &ingredientsList);

        std::map<Ingredients, size_t> _allIngredients;
};

#endif /* !FRIDGE_HPP_ */
