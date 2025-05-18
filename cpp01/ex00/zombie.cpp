// Zombie.cpp
#include "zombie.hpp"

Zombie::Zombie(string name) : name(name) {}

Zombie::~Zombie() {
	std::cout << name << " is destroyed." << "\n";
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
