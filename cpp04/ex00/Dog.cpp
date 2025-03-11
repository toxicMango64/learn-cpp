#include "Dog.hpp"

Dog::Dog() : Animal::Animal("DOG") {
	this->_type = Animal::getType();
	cout << "[C] A new dog appear !" << endl;
}

Dog::Dog(Dog const &src) : Animal::Animal(src) {
	*this = src;
}

Dog &	Dog::operator=(Dog const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

Dog::~Dog() {
	cout << "[D] The dog runs away.." << endl;
}

void	Dog::makeSound() const {
	cout << "[Dog] : Woof Woof!!" << endl;
}