#include "ScavTrap.hpp"

ScavTrap::ScavTrap(string name) : ClapTrap() {
	this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout  << "An evil ScavTrap appear, be careful with " << this->name << " and his " << _attackDamage << " attack damage !" << endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.getName()) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout  << "Evil ScavTrap " << this->name << " exploded." << endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const &rSym) {
	if (this != &rSym) {
		this->name = rSym.getName();
		_hitPoints = rSym.getHitPoints();
		_energyPoints = rSym.getEnergyPoints();
		_attackDamage = rSym.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::attack(const string &target) {
	std::cout  << "Evil ScavTrap " << this->name << " go for broke " << target << " causing him " << _attackDamage << " attack damage" << endl;
}

void	ScavTrap::guardGate() const {
	std::cout  << "Evil ScavTrap " << this->name << " enter in protected mode !" << endl;
}