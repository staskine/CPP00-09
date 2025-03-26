/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:07:40 by sataskin          #+#    #+#             */
/*   Updated: 2025/03/26 12:46:54 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// void capitalize(char &c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// }

// void multiply(int &i)
// {
// 	i *= 3; 
// }

// int main()
// {
// 	char array[5] = {'a', 'B', 'c', 'd', 'f'};
// 	::iter(array, 5, capitalize);
// 	std::cout << "This is our outcome: " << array[0] << " " << array[1] << " " << array[2]<< " " << array[3] << " " << array[4] << std::endl;

// 	int ints[10] = {1, 3, 5, 7, 8, 12, 32, 66, 77, 9};
// 	::iter(ints, 10, multiply);
// 	std::cout << "This is our outcome: ";
// 	for (int i = 0; i < 10; i++) {
// 		std::cout << ints[i] << " ";
// 	}
// 	std::cout << "\n";
// 	return 0;
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  ::iter( tab, 5, print<const int> );
  ::iter( tab2, 5, print<Awesome> );

  return 0;
}