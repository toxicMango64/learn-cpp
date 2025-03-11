#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:

	public:
		FragTrap(string name);
		FragTrap(FragTrap const &src);
		FragTrap();
		~FragTrap();

		FragTrap &	operator=(FragTrap const &rSym);

		void	highFivesGuys(void);
};

#endif