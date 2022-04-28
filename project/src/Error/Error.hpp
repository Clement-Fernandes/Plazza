/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include <exception>
    #include <iostream>
    #include <string>

namespace Error {
    class Error : public std::exception {
        public:
            Error(std::string const &message) throw() : _message(message) {};
            virtual ~Error() throw() {};

        public:
            virtual const char *what() const throw()
            {
                return _message.c_str();
            };
            virtual const char *where() const throw()
            {
                return _message.c_str();
            };
        private:
            std::string _message;
    };

    class File: public Error {
        public:
            File(const std::string &message) throw() : Error("File: " + message) {};
            virtual ~File() throw() {};
    };

    class Order: public Error {
        public:
            Order(const std::string &message) throw() : Error("Order: " + message) {};
            virtual ~Order() throw() {};
    };
}

#endif /* !ERROR_HPP_ */
