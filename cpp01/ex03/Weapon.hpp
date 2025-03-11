#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

using std::string;

class Weapon {
	private:
		string	type;
	public:
		Weapon();
		Weapon(string type);
		~Weapon();

		void			setType(string newtype);
		const string	&getType() const;
};

#endif