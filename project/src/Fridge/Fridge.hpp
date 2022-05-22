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
    #include "Log.hpp"

class Fridge {
    public:
        Fridge(int ingredientTime, std::shared_ptr<Log> log, std::size_t id);
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
        std::shared_ptr<Log> _log;
        std::size_t _id;
        std::map<Ingredients, std::size_t> _allIngredients;
        Clock _clock;
};

#endif /* !FRIDGE_HPP_ */
