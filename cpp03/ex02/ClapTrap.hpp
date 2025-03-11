#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;

class ClapTrap {
	protected:
		string	name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;

	public:
		ClapTrap();
		ClapTrap(string name);
		ClapTrap(ClapTrap const &src);
		virtual ~ClapTrap();

		ClapTrap &	operator=(ClapTrap const &rSym);

		string		getName() const;
		int		getHitPoints() const;
		int		getEnergyPoints() const;
		int		getAttackDamage() const;
		void	setName(string name);
		void	setHitPoints(int hitPoints);
		void	setEnergyPoints(int energyPoints);
		void	setAttackDamage(int attackDamage);

		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif