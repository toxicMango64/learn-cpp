#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal("WRONGCAT") {
	this->_type = WrongAnimal::getType();
	cout << "[C] Something strange approaches.." << endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal::WrongAnimal(src) {
	*this = src;
}

WrongCat &	WrongCat::operator=(WrongCat const &rSym) {
	if (this != &rSym) {
		this->_type = rSym._type;
	}
	return *this;
}

WrongCat::~WrongCat() {
	cout << "[D] Something strange runs away.." << endl;
}
