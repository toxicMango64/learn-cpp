// zombieHorde.cpp
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {

	if (N <= 0) {
		return nullptr;
	}
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}

// Zombie *zombieHorde(int N, const string &name) {
//     if (N <= 0) {
//         return nullptr;
//     }

//     Zombie* horde = new Zombie[N]; // Allocate memory for N Zombies
//     for (int i = 0; i < N; ++i) {
//         horde[i] = Zombie(name); // Use the parameterized constructor
//     }
//     return horde;
// }