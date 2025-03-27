// zombie.cpp
#include "zombie.hpp"

Zombie* newZombie(string name) {
	return new Zombie(name);
}
