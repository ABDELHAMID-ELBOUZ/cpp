#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
class Zombie
{
    private:
        std::string name;
    public:
        void announce( void );
        Zombie();
        ~Zombie();
        std::string SetName(std::string Name);
};

Zombie* zombieHorde(int N, std::string name) ;

#endif