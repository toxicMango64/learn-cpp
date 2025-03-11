#include "Zombie.hpp"

int	main() {
	const int NUM_ZOMBIES = 1410;
	try {
		Zombie	*horde = zombieHorde(NUM_ZOMBIES, "Cyril");
		if (!horde) {
			throw std::runtime_error("Failed to allocate memory for zombies");
		}

		for (int i = 0; i < NUM_ZOMBIES; ++i) {
			horde[i].announce();
		}
		
		delete[] horde;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

// int main() {
// 	const int NUM_ZOMBIES = 1;
//     try {
//         Zombie *horde = zombieHorde(NUM_ZOMBIES, "Cyril");
//         if (!horde) {
//             throw std::runtime_error("Failed to allocate memory for zombies");
//         }
//         for (int i = 0; i < NUM_ZOMBIES; ++i) {
//             horde[i].announce(); // Announce each zombie
//         }
//         delete[] horde; // Free allocated memory
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return 1;
//     }
//     return 0;
// }
