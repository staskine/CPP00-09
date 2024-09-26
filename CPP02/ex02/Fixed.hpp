/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:31:06 by sataskin          #+#    #+#             */
/*   Updated: 2024/09/24 12:07:46 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> 

class Fixed {
	private:
		int FixedPointValue;
		static const int Bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const int val);
		Fixed(const float val);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

        //Comparison overload (return a 0 or 1)
        bool operator==(const Fixed &comp);
        bool operator!=(const Fixed &comp);
        bool operator<(const Fixed &comp);
        bool operator>(const Fixed &comp);
        bool operator<=(const Fixed &comp);
        bool operator>=(const Fixed &comp);

        //Arithmetic operators
        Fixed operator-(const Fixed &arit);
        Fixed operator+(const Fixed &arit);
        Fixed operator/(const Fixed &arit);
        Fixed operator*(const Fixed &arit);
};

std::ostream& operator<<(std::ostream &output, const Fixed &obj);

#endif

/*
        Needed function prototypes

        Fixed operator+(const Fixed &nbr);
        Fixed operator-(const Fixed &nbr);
        Fixed operator*(const Fixed &nbr);
		Fixed operator/(const Fixed &nbr);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
*/

		