#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& dif): weapon(dif) {
    this->name = name;
};

HumanA::~HumanA() {
};

void HumanA::attack() {
    std::cout << this->name << " attacks with their weapon " << this->weapon.getType() << std::endl;
};
