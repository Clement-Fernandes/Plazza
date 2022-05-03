/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Process
*/

#include <unistd.h>
#include <iostream>
#include "Error.hpp"
#include "Process.hpp"

Process::Process()
{
}

Process::Process(int)
{
    _pid = fork();

    if (_pid < 0)
        throw Error::Error("fork failed!");
    std::cout << "Process constructor" << std::endl;
}

Process::~Process()
{
    std::cout << "Process Destructor" << std::endl;
    // exit(0);
}

pid_t Process::getPid() const
{
    return _pid;
}
