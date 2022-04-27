/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
    #define PLAZZA_HPP_

    #include <string>
    #include <vector>

    std::vector<std::string> strToWordArr(std::string const &_line, char delim);

    std::string readFile(std::string const &filename, std::string const &sep);
    void displayFile(std::string const &filename, std::ostream &stream);

    int plazza(std::vector<std::string> const &av);

    void terminalReader();

#endif /* !PLAZZA_HPP_ */
