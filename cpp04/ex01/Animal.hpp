#pragma once

#include <iostream>
#include <string>

typedef std::string string;

class Animal {
	public:
		Animal(string type);
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();

		Animal &	operator=(Animal const &rSym);
		string			getType() const;
		void		setType();

		virtual void	makeSound() const;
	protected:
		string	_type;
};