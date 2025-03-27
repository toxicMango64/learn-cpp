#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

using std::string;
using std::cout;
using std::endl;

class HumanA {
	private:
		string	name;
		Weapon	&weapon;

	public:
		HumanA(const string name, Weapon &weapon);
		~HumanA();

		void	attack() const;
};

#endif
