// Zombie.cpp
#include "Zombie.hpp"

int main() {
	Zombie *zombie = newZombie("John_d");
	zombie->announce();
	delete zombie;

	randomChump("Bob_h");

	return 0;
}
