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

    #include <condition_variable>
    #include <mutex>

class Fridge {
    public:
        Fridge(int ingredientTime);
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void printStatus() const;

        std::condition_variable condition;
        std::mutex mutex;

    protected:
    private:
        bool hasIngredients(std::vector<Ingredients> const &ingredientsList);
        int _ingredientTime;
        std::map<Ingredients, std::size_t> _allIngredients;
};

#endif /* !FRIDGE_HPP_ */
