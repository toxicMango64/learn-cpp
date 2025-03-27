// Zombie.cpp
#include "zombie.hpp"

int main() {
	Zombie *zombie = newZombie("newZombie");
	zombie->announce();
	delete zombie;

	randomChump("randomChump");

	return 0;
}
