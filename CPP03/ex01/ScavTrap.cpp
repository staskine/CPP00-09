/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:14:14 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/30 12:30:59 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string word) : ClapTrap(word) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	if (this == &obj) {
		std::cout << "Copy operator was attempted on itself" << std::endl;
	}
	else {
		std::cout << "ScavTrap Copy assignment operator called" << std::endl;
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->energyPoint = obj.energyPoint;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoint == 0) {
		std::cout << "ScavTrap " << this->name << "is out of hit points" << std::endl;
		return ; 
	}
	if (this->energyPoint == 0) {
		std::cout << "ScavTrap " << this->name << "is out of energy points" << std::endl;
		return ; 
	}
	
	std::cout << "ScavTrap " << this->name <<  " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint -= 1;
}

void ScavTrap::guardGate() {
	std::cout << this->name << " is in Guard Gate mode" << std::endl;
}