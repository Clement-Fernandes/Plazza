/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** IPC
*/

#include <unistd.h>
#include <stdio.h>
#include "Error.hpp"
#include "IPC.hpp"

IPC::IPC()
{
    if (pipe(_com) == -1)
        throw Error::IPC("Pipe failed");
}

IPC::~IPC()
{
}

void IPC::operator <<(std::string const &message)
{
    if (write(_com[Write], message.c_str(), message.size()) == -1)
        throw Error::IPC("Write: Failed to write");
}

void IPC::operator >>(std::string &message)
{
    char *mess = (char *)(void *)malloc(sizeof(char) * 2048);

    if (!mess)
        throw Error::Error("malloc failed");
    if (read(_com[Read], mess, 2047) == -1)
        throw Error::IPC("Read: Failed to read");
    message = mess;
    free(mess);
}
