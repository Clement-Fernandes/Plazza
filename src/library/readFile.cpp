/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** read_file
*/

#include <fstream>
#include "Error.hpp"

std::string readFile(std::string const &filename, std::string const &sep)
{
    std::ifstream f(filename);
    std::string tmp;
    std::string fileContent;
    bool first = true;

    if (!f.is_open())
        throw Error::File("File " + filename + " failed to open");
    while (std::getline(f, tmp)) {
        if (tmp[0] == '#')
            continue;
        if (!first) {
            fileContent.append(sep);
            first = false;
        }
        if (first)
            first = false;
        fileContent.append(tmp);
    }
    return fileContent;
}
