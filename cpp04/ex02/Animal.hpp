#pragma once

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

class Animal {
	public:
		Animal(string type);
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();

		Animal &	operator=(Animal const &rSym);
		string			getType() const;
		void		setType();

		virtual void	makeSound() const = 0;
		virtual void	think() const = 0;
	protected:
		string	_type;
};
