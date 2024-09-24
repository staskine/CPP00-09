/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:31:10 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/20 13:55:16 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->FixedPointValue = 0;
	std::cout << "Default constructor was called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	this->FixedPointValue = obj.FixedPointValue;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	if (this == &obj) {
		std::cout << "Copy operator was attempted on itself" << std::endl;
	}
	else {
		std::cout << "Copy assignment operator called" << std::endl;
		this->FixedPointValue = obj.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits called" << std::endl;
	return this->FixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits called" << std::endl;
	this->FixedPointValue = raw;
}