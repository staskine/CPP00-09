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
};

std::ostream& operator<<(std::ostream &output, const Fixed &obj);

#endif