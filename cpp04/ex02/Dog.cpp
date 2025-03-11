#include "Cat.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal::Animal("DOG") {
	this->_type = Animal::getType();
	cout << "[C] A new dog appear !" << endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal::Animal(src) {
	*this = src;
}

Dog &	Dog::operator=(Dog const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
		this->_brain = rSym._brain;
	}
	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	cout << "[D] The dog runs away.." << endl;
}

void	Dog::makeSound() const {
	cout << "[Dog] : Woof woof" << endl;
}

void	Dog::think() const {
	cout << "[Dog] : " + this->_brain->getRandomIdea() << endl;
}