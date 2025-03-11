#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed const &src) {
	cout << "Copy constructor called" << endl;
	*this = src;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

Fixed&	Fixed::operator=(const Fixed &rSym) {
	cout << "Copy assignement operator called" << endl;
	if (this == &rSym)
		return (*this);
	this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	cout << "getRawBits member function called" << endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	cout << "setRawBits member function called" << endl;
	this->value = raw;
}