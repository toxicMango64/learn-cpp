#include "Cat.hpp"

Cat::Cat() : Animal::Animal("CAT") {
	this->_type = Animal::getType();
	cout << "[C] A new Cat quietly approaches.." << endl;
}

Cat::Cat(Cat const &src) : Animal::Animal(src) {
	*this = src;
}

Cat &	Cat::operator=(Cat const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

Cat::~Cat() {
	cout << "[D] The Cat runs away.." << endl;
}

void	Cat::makeSound() const {
	cout << "[Cat] : Meoww.." << endl;
}