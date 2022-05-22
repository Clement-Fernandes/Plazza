/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Fridge
*/

#ifndef FRIDGE_HPP_
    #define FRIDGE_HPP_

    #include <vector>
    #include <mutex>
    #include <condition_variable>
    #include <map>
    #include "enum.hpp"
    #include "Clock.hpp"


class Fridge {
    public:
        Fridge(int ingredientTime);
        ~Fridge();

        bool getIngredients(std::vector<Ingredients> const &ingredientsList);
        void refillIngredients();
        void printStatus() const;

        std::condition_variable condition;
        std::mutex mutex;

    protected:
    private:
        bool hasIngredients(std::vector<Ingredients> const &ingredientsList);
        int _ingredientTime;
        std::map<Ingredients, std::size_t> _allIngredients;
        Clock _clock;
};

#endif /* !FRIDGE_HPP_ */
