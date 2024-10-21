/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:52:35 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 18:00:08 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "a Dog was found the default way" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal (type) {
	std::cout << "a Dog was constructed with known type" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &obj) : Animal(obj) {
	std::cout << "a Dog was created and copied info" << std::endl;
	this->brain = new Brain(*(obj.brain));
}

Dog& Dog::operator=(const Dog& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "An adorable dog used copy operation" << std::endl;
		this->type = obj.type;
		delete this->brain;
		this->brain = new Brain(*(obj.brain));
	}
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "a Dog was stolen by me (can't think of destroying)" << std::endl;	
}

void Dog::makeSound() const {
	std::cout << "Dog " << this->type << " says = <Woof!>" << std::endl;
}

std::string Dog::getIdea(unsigned int i) {
	if (i > 99) {
		std::cout << "Setting idea to default error of my choice\n";
		return "Went beyond scope";
	}
	return this->brain->getIdea(i);
}

void Dog::setIdea(std::string brainfart, unsigned int i) {
	if (i > 99) {
		std::cout << "Can't go beyond brains abilities\n";
	}
	else  {
		this->brain->setIdea(brainfart, i);
	}
}