/*
** EPITECH PROJECT, 2022
** B-CCP-400-PAR-4-1-theplazza-clement.fernandes
** File description:
** Process
*/

#ifndef PROCESS_HPP_
    #define PROCESS_HPP_

    #include <unistd.h>

class Process {
    public:
        Process();
        Process(int);
        ~Process();

        pid_t getPid() const;
    protected:
    private:
        pid_t _pid;
};

#endif /* !PROCESS_HPP_ */
