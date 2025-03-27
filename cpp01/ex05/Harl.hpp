#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

using std::string;

class Harl {
	private:
		void	debug() const;
		void	info() const;
		void	warning() const;
		void	error() const;

		public:
				Harl();
			~Harl();

	void	complain(string level);
};

#endif
