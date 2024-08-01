#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(nullptr) {
    this->name = name;
};

HumanB::~HumanB() {
};

void HumanB::attack() {
    if (weapon == nullptr)
        std::cout << "Error! Pls set a weapon ;_;" << std::endl;
    else
        std::cout << this->name << " attacks with their weapon " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}