#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::Fixed(const int n) {
	rawBits = n << bits;
}

Fixed::Fixed(const float f) : rawBits(f) {
	rawBits = roundf(f * (1 << bits));
}

Fixed::~Fixed() {
}

Fixed&	Fixed::operator=(Fixed const &rSym) {
	if (this != &rSym)
		rawBits = rSym.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const &rSym) const {
	return Fixed(this->toFloat() + rSym.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rSym) const {
	return Fixed(this->toFloat() - rSym.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rSym) const {
	return Fixed(this->toFloat() * rSym.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rSym) const {
	return Fixed(this->toFloat() / rSym.toFloat());
}

bool	Fixed::operator<(Fixed const &rSym) const {
	if (this->getRawBits() < rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(Fixed const &rSym) const {
	if (this->getRawBits() > rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const &rSym) const {
	if (this->getRawBits() <= rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const &rSym) const {
	if (this->getRawBits() >= rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const &rSym) const {
	if (this->getRawBits() == rSym.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const &rSym) const {
	if (this->getRawBits() != rSym.getRawBits())
		return true;
	return false;
}

Fixed&	Fixed::operator++() {
	rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	operator++();
	return tmp;
}

Fixed&	Fixed::operator--() {
	rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	operator--();
	return tmp;
}

int		Fixed::getRawBits() const {
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

Fixed &	Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return b;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) {
	o << rSym.toFloat();
	return o;
}