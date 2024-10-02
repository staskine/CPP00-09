/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:52:35 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/02 11:12:16 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "a Dog was found the default way" << std::endl;
	this->type = "Dog";
}

Dog::Dog(std::string type) : Animal (type) {
	std::cout << "a Dog was constructed with known type" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
	std::cout << "a Dog was created and copied info" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "An adorable dog used copy operation" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "a Dog was stolen by me (can't think of destroying)" << std::endl;	
}

void Dog::makeSound() const {
	std::cout << "Dog " << this->type << " says = <Woof!>" << std::endl;
}