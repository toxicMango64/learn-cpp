// Zombie.hpp
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

using std::string;

class Zombie {
	private:
		string name;

	public:
		Zombie(string name);
		~Zombie();
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump(string name);

#endif // ZOMBIE_HPP
