#include "ClapTrap.hpp"

ClapTrap::ClapTrap(string name) : name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout  << std::setw(15) << "ClapTrap \"" << name << "\" was created with :" << endl;
	std::cout  << std::setw(27) << "HP : " << _hitPoints << endl;
	std::cout  << std::setw(27) << "Energy Points : " << _energyPoints << endl;
	std::cout  << std::setw(27) << "Attack Damage : " << _attackDamage << endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
}

ClapTrap::ClapTrap() {
	std::cout  << "Basic ClapTrap was created : ";
}

ClapTrap::~ClapTrap() {
	std::cout  << "ClapTrap " << this->name << " was destringoy." << endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const &rSym) {
	if (this != &rSym) {
		this->name = rSym.getName();
		_hitPoints = rSym.getHitPoints();
		_energyPoints = rSym.getEnergyPoints();
		_attackDamage = rSym.getAttackDamage();
	}
	return *this;
}

string	ClapTrap::getName() const {
	return this->name;
}
int	ClapTrap::getHitPoints() const {
	return _hitPoints;
}
int	ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}
int	ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void	ClapTrap::setName(string name) {
	this->name = name;
}
void	ClapTrap::setHitPoints(int hitPoints) {
	_hitPoints = hitPoints;
}
void	ClapTrap::setEnergyPoints(int energyPoints) {
	_energyPoints = energyPoints;
}
void	ClapTrap::setAttackDamage(int attackDamage) {
	_attackDamage = attackDamage;
}

void	ClapTrap::attack(const string &target) {
	if (_energyPoints > 0) {
		std::cout  << "ClapTrap " << this->name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << endl;
		_energyPoints -= 1;
	}
	else
		std::cout  << "ClapTrap " << this->name << " doesn't have enough energy points !" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout  << "Ouch ! " << this->name << " lose " << amount << " hp !" << endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout  << "ClapTrap " << this->name << " repair itself and gain " << amount << " hp !" << endl;
	_hitPoints += amount;
}