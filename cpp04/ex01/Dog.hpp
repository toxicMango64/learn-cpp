#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

using std::string;
using std::endl;
using std::cout;

class Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		virtual ~Dog();

		Dog &	operator=(Dog const &rSym);

		void			makeSound() const;
		virtual void	think() const;
	private:
		string		_type;
		Brain	*_brain;
};