/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** IMutex
*/

#ifndef IMUTEX_HPP_
    #define IMUTEX_HPP_

class IMutex {
    public :
        virtual ~IMutex() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual void trylock() = 0;
};


#endif /* !IMUTEX_HPP_ */
