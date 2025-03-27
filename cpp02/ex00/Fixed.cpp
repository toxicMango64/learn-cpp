#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	cout << "Default constructor called" << "\n";
}

Fixed::Fixed(Fixed const &src) {
	cout << "Copy constructor called" << "\n";
	*this = src;
}

Fixed::~Fixed() {
	cout << "Destructor called" << "\n";
}

Fixed&	Fixed::operator=(const Fixed &rSym) {
	cout << "Copy assignement operator called" << "\n";
	if (this == &rSym)
		return (*this);
	this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	cout << "getRawBits member function called" << "\n";
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	cout << "setRawBits member function called" << "\n";
	this->value = raw;
}