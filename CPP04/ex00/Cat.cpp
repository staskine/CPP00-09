/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:44:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/02 11:12:28 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "a Cat was found the default way" << std::endl;
	this->type = "Cat";
}

Cat::Cat(std::string type) : Animal (type) {
	std::cout << "a Cat was constructed with known type" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj) {
	std::cout << "a Cat was created and copied info" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "A smart cat used copy operation" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "a Cat was destroyed humanely" << std::endl;	
}

void Cat::makeSound() const {
	std::cout << "Cat " << this->type << " says = <Meow!> and hisses" << std::endl;
}