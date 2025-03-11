#pragma once

#include "Animal.hpp"

using std::string;
using std::endl;
using std::cout;

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

		Cat &	operator=(Cat const &rSym);

		void	makeSound() const;
	private:
		string		_type;
};