/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Log
*/

#ifndef LOG_HPP_
    #define LOG_HPP_

    #include <fstream>

class Log {
    public:
        Log();
        ~Log();

        void operator <<(std::string const &message);
    protected:
    private:
        std::ofstream _stream;
};

#endif /* !LOG_HPP_ */
