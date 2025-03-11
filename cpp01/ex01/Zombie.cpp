// Zombie.cpp
#include "Zombie.hpp"

// Zombie::Zombie() : name("Unnamed Zombie") { // Initialize with a default name
//     std::cout << "Be careful! A new zombie is in the house!" << std::endl;
// }

// Zombie::Zombie(string name) : name(name) {} // Constructor with name

// Zombie::~Zombie() {
//     std::cout << "A zombie died a second time." << std::endl;
// }

// void Zombie::announce() const {
//     std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
// }

Zombie::Zombie() {
	std::cout << "Be careful ! a new zombie is in the house !" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "A zombie died a second time." << std::endl;
}

void	Zombie::announce() const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(string name) {
	this->name = name;
}