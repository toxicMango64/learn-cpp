#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	rawBits = n << bits;
}

Fixed::Fixed(const float f) : rawBits(f) {
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(f * (1 << bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &rSym) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rSym)
		rawBits = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void	Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

float	Fixed::toFloat() const {
	return (float)rawBits / (float)(1 << bits);
}

int		Fixed::toInt() const {
	return rawBits >> bits;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) {
	o << rSym.toFloat();
	return o;
}