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
	Zombie(); // Default constructor
	~Zombie();
	void  announce() const;
	void  setName(string name);
};

Zombie	*newZombie(string name);
Zombie	*zombieHorde(int N, string name);

#endif // ZOMBIE_HPP
