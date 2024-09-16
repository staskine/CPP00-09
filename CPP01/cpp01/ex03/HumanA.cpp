/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:24 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 17:18:31 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
