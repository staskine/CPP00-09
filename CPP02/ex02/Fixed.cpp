/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:31:10 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/26 16:21:33 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors

Fixed::Fixed() {
	this->FixedPointValue = 0;
}

Fixed::Fixed(const int val) {
	this->FixedPointValue = val << this->Bits;
};

Fixed::Fixed(const float val) {
	this->FixedPointValue = roundf(val * (float)(1 << this->Bits));
};

Fixed::Fixed(const Fixed &obj) {
	this->FixedPointValue = obj.FixedPointValue;
}

//Making fixed point values

float Fixed::toFloat(void) const {
	return (this->FixedPointValue / (float)(1 << this->Bits));
}

int Fixed::toInt(void) const {
	return (this->FixedPointValue >> this->Bits);
}

// Destructor

Fixed::~Fixed() {
	
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
	else 
	{
		this->FixedPointValue = obj.getRawBits();
	}
	return (*this);
}

//Comparison

bool Fixed::operator==(const Fixed &comp) {
    return (this->FixedPointValue == comp.getRawBits());
}

bool Fixed::operator!=(const Fixed &comp) {
    return (this->FixedPointValue != comp.getRawBits());
}

bool Fixed::operator<(const Fixed &comp) {
    return (this->FixedPointValue < comp.getRawBits());
}

bool Fixed::operator>(const Fixed &comp) {
    return (this->FixedPointValue > comp.getRawBits());
}

bool Fixed::operator<=(const Fixed &comp) {
    return (this->FixedPointValue <= comp.getRawBits());
}

bool Fixed::operator>=(const Fixed &comp) {
    return (this->FixedPointValue >= comp.getRawBits());
}

//Arithmetics

Fixed Fixed::operator-(const Fixed &arit) {
	Fixed temp;
	temp.setRawBits(this->FixedPointValue - arit.getRawBits());
    return temp;
}

Fixed Fixed::operator+(const Fixed &arit) {
    Fixed temp;
	temp.setRawBits(this->FixedPointValue + arit.getRawBits());
    return temp;
}

Fixed Fixed::operator/(const Fixed &arit) {
	Fixed temp;
	if (arit.getRawBits() == 0) {
		std::cout << "Don't divide with Zero" << std::endl;
		return temp;
	} 
	temp.setRawBits((this->FixedPointValue << this->Bits) / arit.getRawBits());
	return temp;
}

Fixed Fixed::operator*(const Fixed &arit) {
	Fixed temp;
	temp.setRawBits((this->FixedPointValue * arit.getRawBits()) >> this->Bits);
	return temp;
}

//Pre Increment and decrement

Fixed &Fixed::operator++(void) {
	this->FixedPointValue += 1;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	this->FixedPointValue -= 1;
	return (*this);
}

//Post Increment and decrement

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->FixedPointValue += 1;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	this->FixedPointValue -= 1;
	return (tmp);
}

//Min and Max functions

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

std::ostream& operator<<(std::ostream &output, const Fixed &obj) {
	output << obj.toFloat();
	return output;
}