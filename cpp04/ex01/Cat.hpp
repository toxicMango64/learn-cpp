#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

using std::string;
using std::endl;
using std::cout;

class Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		virtual ~Cat();

		Cat &	operator=(Cat const &rSym);

		void			makeSound() const;
		virtual void	think() const;
	private:
		string	_type;
		Brain	*_brain;
};
