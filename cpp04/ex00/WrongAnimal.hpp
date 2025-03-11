#pragma once

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

class WrongAnimal {
	public:
		WrongAnimal(string type);
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal();

		WrongAnimal &	operator=(WrongAnimal const &rSym);
		string			getType() const;
		void		setType();

		void	makeSound() const;
	protected:
		string	_type;
};