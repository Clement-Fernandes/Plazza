/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <chrono>
#include <math.h>

using timePoint = std::chrono::time_point<std::chrono::system_clock>;

class Clock {
    public:
        Clock();
        ~Clock();

        timePoint getClockStart();
        timePoint getClockEnd();

        void start();
        void restart();

        long long int getElapsedTime(bool toSeconds = false);

    protected:
    private:
        timePoint _start;
        timePoint _end;
        long long int _elapsedTime;
};

#endif /* !CLOCK_HPP_ */
