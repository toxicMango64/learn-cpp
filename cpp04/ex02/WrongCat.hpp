#pragma once

#include "WrongAnimal.hpp"

using std::string;
using std::endl;
using std::cout;

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		~WrongCat();

		WrongCat &	operator=(WrongCat const &rSym);

		void	makeSound() const;
	private:
		string		_type;
};