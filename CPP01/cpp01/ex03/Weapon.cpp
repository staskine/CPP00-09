/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:36:49 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/16 14:36:50 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const{
    return this->type;
};

void Weapon::setType(std::string type) {
    this->type = type;
};

Weapon::Weapon(std::string name) {
    this->type = name;
};

Weapon::~Weapon() {
};

Weapon::Weapon() {
};
