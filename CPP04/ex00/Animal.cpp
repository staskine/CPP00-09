/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:30:20 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/02 11:44:58 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "an animal was found the default way" << std::endl;
	this->type = "UNKNOWN";
}

Animal::Animal(std::string type) {
	std::cout << "an animal was constructed with known type" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal &obj) {
	std::cout << "an animal was created and copied info" << std::endl;
	this->type = obj.type;
}

Animal& Animal::operator=(const Animal& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "animal copying operation done (is this illegal?)" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "an animal was disposed of humanely" << std::endl;	
}

void Animal::makeSound() const {
	std::cout << "Animal " << this->type << " is making random animal sounds" << std::endl;
}

std::string& Animal::getType() const {
	return (std::string&)this->type;
}
