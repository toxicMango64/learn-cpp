#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"
# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class Phonebook {
	private:
		static const int MAX_CAPACITY = 8;
		Contact	contacts[MAX_CAPACITY];
		int		index;
		int		contactCount;
	public:
		Phonebook();
		~Phonebook();
		void	addContact();
		void	searchContact();
};

#endif
