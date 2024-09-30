/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:43:44 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/30 13:54:43 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string word) : ClapTrap(word) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	if (this == &obj) {
		std::cout << "Copy operator was attempted on itself" << std::endl;
	}
	else {
		std::cout << "FragTrap Copy assignment operator called" << std::endl;
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->energyPoint = obj.energyPoint;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << this->name << " is high fiving guys as the name suggests" << std::endl;
}