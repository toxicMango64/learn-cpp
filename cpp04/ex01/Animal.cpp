#include "Animal.hpp"
#include "Dog.hpp"

Animal::Animal(string type) : _type(type) {
	std::cout  << "[C] Animal base constructor called for type : " << this->_type << "." << endl;
}

Animal::Animal() : _type("UNKNOWN") {
	std::cout  << "[C] Animal default constructor called." << endl;
}

Animal::Animal(Animal const &src) {
	*this = src;
}

Animal &	Animal::operator=(Animal const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout  << "[D] Default destructor called for type : " << this->_type << "." << endl;
}

string	Animal::getType() const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout  << "[Unknown Animal] Grrr..." << endl;
}