#include "Zombie.hpp"

void Zombie::setname(std::string name) {
    this->name = name;
};

Zombie::~Zombie() {
};

void    Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}