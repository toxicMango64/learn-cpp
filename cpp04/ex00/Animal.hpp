#pragma once

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;

/**
 * @brief 
 */
class Animal {
	protected:
		string	_type;
	public:
		Animal(string type);
		Animal();
		Animal(Animal const &src);
		virtual ~Animal(); // Make the destructor virtual

		Animal &	operator=(Animal const &rSym);
		string			getType() const;
		void		setType();

		virtual void	makeSound() const;
};