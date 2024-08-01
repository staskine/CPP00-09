#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
};

Zombie::~Zombie() {
};

void    Zombie::announce() {
    stdc::out << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}