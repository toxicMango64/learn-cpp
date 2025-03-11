#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(string name) : name(name) {
	return ;
}

HumanB::~HumanB() {
	return ;
}

void	HumanB::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	return ;
}