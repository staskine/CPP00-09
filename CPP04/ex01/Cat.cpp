/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:44:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/03 17:59:58 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "a Cat was found the default way" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "a Cat was constructed with known type" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj) {
	std::cout << "a Cat was created and copied info" << std::endl;
	this->brain = new Brain(*(obj.brain));
}

Cat& Cat::operator=(const Cat& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "A smart cat used copy operation" << std::endl;
		this->type = obj.type;
		delete this->brain;
		this->brain = new Brain(*(obj.brain));
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "a Cat was destroyed humanely" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat " << this->type << " says = <Meow!> and hisses" << std::endl;
}

std::string Cat::getIdea(unsigned int i) {
	if (i > 99) {
		std::cout << "Setting idea to default error of my choice\n";
		return "Went beyond scope";
	}
	return this->brain->getIdea(i);
}

void Cat::setIdea(std::string brainfart, unsigned int i) {
	if (i > 99) {
		std::cout << "Can't go beyond brains abilities\n";
	}
	else  {
		this->brain->setIdea(brainfart, i);
	}
}