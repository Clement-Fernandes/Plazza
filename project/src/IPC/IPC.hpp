/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** IPC
*/

#ifndef IPC_HPP_
    #define IPC_HPP_

    #include <string>

class IPC {
    public:
        IPC();
        ~IPC();

        void operator <<(std::string const &message);
        void operator >>(std::string &message);
    protected:
    private:
        enum ComChanel {
            Read = 0,
            Write = 1
        };
        int _com[2];
};

#endif /* !IPC_HPP_ */
