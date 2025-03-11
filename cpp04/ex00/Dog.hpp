#pragma once

#include "Animal.hpp"

using std::string;
using std::endl;
using std::cout;

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();

		Dog &	operator=(Dog const &rSym);

		void	makeSound() const;
	private:
		string		_type;
};