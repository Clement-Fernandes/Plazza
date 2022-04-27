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
#include "plazza.hpp"

static bool catchHelper(std::vector<std::string> const &av)
{
    bool helper = false;
    std::map<std::string, std::string> helper_list {
    {"-h", "conf/helper.conf"},
    {"--helper", "conf/helper.conf"},
    {"--size", "conf/size.conf"},
    {"--type", "conf/pizza.conf"}};

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

int main(int ac, char const * const *av)
{
    if (ac < 2) {
        displayFile("conf/helper.conf", std::cerr);
        return 84;
    }
    if (catchHelper(std::vector<std::string> (av, av + ac)))
        return 0;
    return plazza(std::vector<std::string> (av, av + ac));
}
