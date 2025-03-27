#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;

	cout << a.getRawBits() << "\n";
	cout << b.getRawBits() << "\n";
	cout << c.getRawBits() << "\n";
	
	return 0;
}
