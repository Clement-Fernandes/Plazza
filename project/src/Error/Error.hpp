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
            File(std::string const &message, bool colored = false) throw() : Error((colored) ? ("\033[1;31mFile: " + message + "\033[0m") : ("File: " + message)) {};
            virtual ~File() throw() {};
    };

    class Order: public Error {
        public:
            Order(std::string const &message, bool colored = false) throw() : Error((colored) ? ("\033[1;31mOrder: " + message + "\033[0m") : ("Order: " + message)) {};
            virtual ~Order() throw() {};
    };

    class Fridge : public Error {
        public:
            Fridge(std::string const &message, bool colored = false) throw() : Error((colored) ? ("\033[1;31mFridge: " + message + "\033[0m") : ("Fridge: " + message)) {};

            virtual ~Fridge() throw() {};
    };

    class IPC : public Error {
        public:
            IPC(std::string const &message, bool colored = false) throw() : Error((colored) ? ("\033[1;31mIPC: " + message + "\033[0m") : ("IPC: " + message)) {};

            virtual ~IPC()  throw() {};
    };
}

#endif /* !ERROR_HPP_ */
