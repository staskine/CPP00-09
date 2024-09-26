#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed c(10);
    Fixed d(2);
    Fixed e(3);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "Some basic arithmetic operations " << std::endl;
    std::cout << "result should be 10.0078 = " << c + a << std::endl;
    std::cout << "result should be 12 = " << c + d << std::endl;
    std::cout << "result should be 8 = " << c - d << std::endl;
    std::cout << "result should be 5 = " << e + d << std::endl;
    std::cout << "result should be 5 = " << c / d << std::endl;
    std::cout << "result should be 30 = " << c * e << std::endl;
    std::cout << "result should be 1 = " << e - d << std::endl;
    std::cout << "result should be 3.33 = " << c / e << std::endl;
    std::cout << Fixed::max(c,d) << std::endl;
    return 0;
}

//The pdf main
/*
int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    //std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}
Result of running this main is supposed to be
$> ./a.out
0 a
0.00390625 ++a
0.00390625 a
0.00390625 a++
0.0078125 a
10.1016  b
10.1016 max
$>
*/