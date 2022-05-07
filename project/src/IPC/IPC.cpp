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
    char *mess = static_cast<char *>(malloc(sizeof(char) * 16));

    if (!mess)
        throw Error::Error("malloc failed");
    message.clear();
    int value = read(_com[Read], mess, sizeof(mess));
    if (value == -1)
        throw Error::IPC("Read: Failed to read");
    for (int i = 0; i != value; i++)
        message += mess[i];
    free(mess);
}
