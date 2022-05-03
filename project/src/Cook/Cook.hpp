/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

    #include "Fridge.hpp"

class Cook {
    public:
        Cook(Fridge &kitchenFridge);
        ~Cook();

    protected:
    private:
        Fridge _kitchenFridge;
};

#endif /* !COOK_HPP_ */
