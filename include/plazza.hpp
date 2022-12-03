/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
    #define PLAZZA_HPP_

    #define ERROR_EXIT 84
    #define SUCCESS_EXIT 0

    #include <string>
    #include <vector>

int plazza(std::vector<std::string> const &av);

std::vector<std::string> strToWordArr(std::string const &_line, char delim);

std::string readFile(std::string const &filename, std::string const &sep);
void displayFile(std::string const &filename, std::ostream &stream);

/* enum for color code */
enum COLOR {
    DEFAULT = 0,
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    PURPLE = 35,
    CYAN = 36,
    WHITE = 37
};

/* Print text with optionnal color or line break */
void printText(std::string const &text, enum COLOR color = COLOR::DEFAULT, bool lineBreak = true);

#endif /* !PLAZZA_HPP_ */
