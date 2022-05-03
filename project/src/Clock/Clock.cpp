/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock()
{
}

Clock::~Clock()
{
}

timePoint Clock::getClockStart()
{
    return (_start);
}

timePoint Clock::getClockEnd()
{
    return (_end);
}

void Clock::start()
{
    _start = std::chrono::system_clock::now();
}

void Clock::restart()
{
    _start = std::chrono::system_clock::now();
}

long long int Clock::getElapsedTime()
{
    _end = std::chrono::system_clock::now();
    _elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();

    return (_elapsedTime);
};