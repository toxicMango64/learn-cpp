#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(string type) : _type(type) {
	std::cout  << "[C] WrongAnimal base constructor called for type : " << this->_type << "." << endl;
}

WrongAnimal::WrongAnimal() : _type("UNKNOWN") {
	std::cout  << "[C] WrongAnimal default constructor called." << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	*this = src;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout  << "[D] Default destructor called for type : " << this->_type << "." << endl; 
}

string	WrongAnimal::getType() const {
	return this->_type;
}

void	WrongAnimal::makeSound() const {
	std::cout  << "[Unknown WrongAnimal] Grrbadabibobidap..." << endl;
}