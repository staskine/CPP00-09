/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:31:10 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/24 12:09:13 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->FixedPointValue = 0;
	std::cout << "Default constructor was called" << std::endl;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	this->FixedPointValue = val << this->Bits;
};

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->FixedPointValue = roundf(val * (float)(1 << this->Bits));
};

Fixed::Fixed(const Fixed &obj) {
	this->FixedPointValue = obj.FixedPointValue;
	std::cout << "Copy constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return (this->FixedPointValue / (float)(1 << this->Bits));
}

int Fixed::toInt(void) const {
	return (this->FixedPointValue >> this->Bits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return this->FixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	this->FixedPointValue = raw;
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

std::ostream& operator<<(std::ostream &output, const Fixed &obj) {
	output << obj.toFloat();
	return output;
}