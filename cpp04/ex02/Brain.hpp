#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>

using std::string;
using std::endl;
using std::cout;

class Brain {
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();

		Brain &	operator=(Brain const &rSym);

		string		getRandomIdea() const;
	private:
		string		ideaGenerator() const;
		
		string		_ideas[100];
};