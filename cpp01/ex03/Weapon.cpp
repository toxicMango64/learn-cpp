#include "Weapon.hpp"

Weapon::Weapon() {
	return ;
}

Weapon::Weapon(string type) {
	this->type = type;
	return ;
}

Weapon::~Weapon() {
	return ;
}

const string	&Weapon::getType() const {
	return this->type;
}


void	Weapon::setType(string ntype) {
	this->type = ntype;
}
