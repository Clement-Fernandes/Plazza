/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include <memory>
    #include <string>
    #include <iostream>

class Kitchen {
    public:
        Kitchen(float cookingTime, size_t nbCooks, int ingredientTime, int writer, int reader);
        ~Kitchen();

        void loop();

    protected:
    private:
        float _cookingTime;
        size_t _nbCooks;
        int _ingredientTime;
        int _writer;
        int _reader;
};

#endif /* !KITCHEN_HPP_ */
