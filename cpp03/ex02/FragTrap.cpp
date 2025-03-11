#include "FragTrap.hpp"

FragTrap::FragTrap(string name) : ClapTrap() {
	this->name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << "The heroic FragTrap " << this->name << " enter in the arena to kill the vilains !" << endl;
}

FragTrap::FragTrap(FragTrap const &src) {
	*this = src;
}

FragTrap::~FragTrap() {
	cout << "The heroic FragTrap " << this->name << " plant his sword into the ground, and leave this world with dignity." << endl;
}

FragTrap &	FragTrap::operator=(FragTrap const &rSym) {
	if (this != &rSym) {
		this->name = rSym.getName();
		_hitPoints = rSym.getHitPoints();
		_energyPoints = rSym.getEnergyPoints();
		_attackDamage = rSym.getAttackDamage();
	}
	return *this;
}

void	FragTrap::highFivesGuys() {
	cout << this->name << " : Who wants a high-five ?" << endl;
}