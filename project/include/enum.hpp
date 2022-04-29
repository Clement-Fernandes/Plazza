/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** enum
*/

#ifndef ENUM_HPP_
    #define ENUM_HPP_

    enum class PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum class PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    enum class Ingredients
    {
        DOE = 0,
        TOMATOE,
        GRUYERE,
        HAM,
        MUSHROOMS,
        STEAK,
        EGGPLANT,
        GOATCHEESE,
        CHIEFLOVE
    };

#endif /* !ENUM_HPP_ */
