/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Process
*/

#include "Error.hpp"
#include "Process.hpp"

Process::Process()
{
    _pid = fork();

    if (_pid < 0)
        throw Error::Error("fork failed!");
}

Process::~Process()
{
}

pid_t Process::getPid() const
{
    return _pid;
}
