/*
** EPITECH PROJECT, 2022
** plazza
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
    #define PLAZZA_HPP_

    #include <string>

    std::string readFile(std::string const &filename, std::string const &sep);
    void display_file(std::string const &filename, std::ostream &stream = std::cout);

#endif /* !PLAZZA_HPP_ */
