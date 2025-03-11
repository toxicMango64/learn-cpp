#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:

	public:
		ScavTrap(string name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();

		ScavTrap &	operator=(ScavTrap const &rSym);
		
		void	attack(const string &target);
		void	guardGate() const;
};

#endif