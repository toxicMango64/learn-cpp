#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const string name, Weapon &weapon) : name(name), weapon(weapon) {
	return ;
}

HumanA::~HumanA() {
	return ;
}

void	HumanA::attack() const {
	cout << this->name << " attacks with their " << this->weapon.getType() << endl;
	return ;
}
