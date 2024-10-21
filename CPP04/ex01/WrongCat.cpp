/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:44:04 by sataskin          #+#    #+#             */
/*   Updated: 2024/10/02 11:38:57 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "a WrongCat was found the default way" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(std::string type) : WrongAnimal (type) {
	std::cout << "a WrongCat was constructed with known type" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj) {
	std::cout << "a WrongCat was created and copied info" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	if (this == &obj) {
		std::cout << "self copying attempted :(" << std::endl;
	}
	else
	{
		std::cout << "A smart WrongCat used copy operation" << std::endl;
		this->type = obj.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "a WrongCat was destroyed" << std::endl;	
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat " << this->type << " says = <hiss!>" << std::endl;
}