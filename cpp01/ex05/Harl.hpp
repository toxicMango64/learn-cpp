#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

using std::string;

class Harl {
	public:
		Harl();
		~Harl();

		void	complain(string level);

	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;
};

#endif
