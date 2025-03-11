// Zombie.cpp
#include "Zombie.hpp"

Zombie::Zombie(string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
