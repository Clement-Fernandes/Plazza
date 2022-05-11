/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** main
*/

#include <iostream>
#include <algorithm>
#include <array>
#include <map>
#include <regex>
#include "plazza.hpp"

static bool catchHelper(std::vector<std::string> const &av)
{
    bool helper = false;
    std::map<std::string, std::string> helper_list {
        {"-h", "conf/helper.conf"},
        {"--helper", "conf/helper.conf"},
        {"--size", "conf/size.conf"},
        {"--type", "conf/pizza.conf"}
    };

    for (auto i = helper_list.begin(); i != helper_list.end(); i++) {
        if (std::find(av.begin(), av.end(), i->first) != av.end()) {
            if (helper)
                std::cout << std::endl;
            displayFile(i->second, std::cout);
            helper = true;
        }
    }
    return helper;
}

static bool check_args(char const * const *av)
{
    bool check = true;
    std::regex reg_float("([0-9]*[.])?[0-9]+");
    std::regex reg_int("[0-9]+");
    if (!regex_match(av[1], reg_float) || !regex_match(av[2], reg_int) || !regex_match(av[3], reg_int))
        check = false;
    return (check);
}

int main(int ac, char const * const *av)
{
    if (catchHelper(std::vector<std::string> (av, av + ac))) {
        return SUCCESS_EXIT;
    } else if (ac == 4) {
        if (!check_args(av)) {
            displayFile("conf/helper.conf", std::cerr);
            return ERROR_EXIT;
        }
        plazza(std::vector<std::string> (av, av + ac));
    } else {
        displayFile("conf/helper.conf", std::cerr);
        return ERROR_EXIT;
    }
    return SUCCESS_EXIT;
}
