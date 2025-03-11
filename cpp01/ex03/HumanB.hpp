#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

using std::string;

class HumanB {
	private:
		string	name;
		Weapon	*weapon;

	public:
		HumanB(string name);
		~HumanB();
		
		void	attack() const;
		void	setWeapon(Weapon &weapon);
};

#endif