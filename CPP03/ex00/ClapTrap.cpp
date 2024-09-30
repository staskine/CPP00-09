/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:02:28 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/30 10:43:17 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	this->name = "JaneDoe";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;	
}

ClapTrap::ClapTrap(std::string word) {
	std::cout << "Default constructor called" << std::endl;
	this->name = word;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;	
}

ClapTrap::ClapTrap(const ClapTrap &obj) {
	std::cout << "Copy constructor called" << std::endl;
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;	
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	if (this == &obj) {
		std::cout << "Copy operator was attempted on itself" << std::endl;
	}
	else {
		std::cout << "Copy assignment operator called" << std::endl;
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->energyPoint = obj.energyPoint;
		this->attackDamage = obj.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoint == 0) {
		std::cout << "ClapTrap " << this->name << "is out of hit points" << std::endl;
		return ; 
	}
	if (this->energyPoint == 0) {
		std::cout << "ClapTrap " << this->name << "is out of energy points" << std::endl;
		return ; 
	}
	
	std::cout << "ClapTrap " << this->name <<  " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint -= 1; 
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoint == 0) {
		std::cout << "ClapTrap " << this->name << "is already dead" << std::endl;
		return ; 
	}
	if (amount > this->hitPoint) {
		std::cout << "ClapTrap " << this->name << " took " << this->hitPoint << " of damage" << std::endl;
		this->hitPoint = 0;
	}
	else {
		this->hitPoint -= amount;
		std::cout << "ClapTrap " << this->name << " took " << amount << " of damage" << std::endl;
	}
	 
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoint == 0) {
		std::cout << "ClapTrap " << this->name << "is out of hit points" << std::endl;
		return ; 
	}
	if (this->energyPoint == 0) {
		std::cout << "ClapTrap " << this->name << "is out of energy points" << std::endl;
		return ; 
	}
	
	std::cout << "ClapTrap " << this->name <<  " healed " << amount << " of hit points " << std::endl;
	this->energyPoint -= 1;
	this->hitPoint += amount;
}