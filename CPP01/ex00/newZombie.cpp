#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    return new Zombie(name);    
}

//It creates a zombie, name it, and return it so you can use it outside of the functionscope.