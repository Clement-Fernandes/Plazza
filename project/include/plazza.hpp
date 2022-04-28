/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
    #define PLAZZA_HPP_

    #include <string>
    #include <vector>

int plazza(std::vector<std::string> const &av);

std::vector<std::string> strToWordArr(std::string const &_line, char delim);

std::string readFile(std::string const &filename, std::string const &sep);
void displayFile(std::string const &filename, std::ostream &stream);

void terminalReader();


#endif /* !PLAZZA_HPP_ */
