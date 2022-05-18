/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Log
*/

#include "Error.hpp"
#include "Log.hpp"

Log::Log()
{
    _stream.open("conf/log/logfile.log", std::ios::out);

    if (!_stream) {
        _stream.close();
        throw Error::Log("file failed to open");
    }
}

Log::~Log()
{
    _stream.close();
}

void Log::operator <<(std::string const &message)
{
    _stream << message << std::endl;
}
