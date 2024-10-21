/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:39:52 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/02 11:38:24 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "a WrongAnimal was found the default way" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type) {
	std::cout << "a WrongAnimal was constructed with known type" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
	std::cout << "a WrongAnimal was created and copied info" << std::endl;
	this->type = obj.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "WrongAnimal used copy operation" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "a WrongAnimal was destroyed in a wrong way" << std::endl;	
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal " << this->type << " says = <wrong!!!!>" << std::endl;
}

std::string& WrongAnimal::getType() const {
	return (std::string&)this->type;
}