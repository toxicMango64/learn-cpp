#include "Phonebook.hpp"

int main() {
	Phonebook phonebook;
	std::string choice;

	std::system("clear");
	std::cout << "Welcome to the Phonebook!\n" << std::endl;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

		if (!std::getline(std::cin, choice)) {
			if (std::cin.eof()) {
				std::cout << "Exiting the Phonebook. Goodbye!" << std::endl;
				exit (0);
			} else {
				std::cerr << "Error reading input." << std::endl;
				exit (0);
			}
		}

		if (choice.empty()) {
			continue ;
		}

		if ("ADD" == choice) {
			std::cin.clear();
			// std::cin.ignore(10000, '\n');
			phonebook.addContact();
		}
		else if ("SEARCH" == choice) {
			std::system("clear");
			phonebook.searchContact();
		}
		else if ("EXIT" == choice) {
			std::cout << "Exiting the Phonebook. Goodbye!" << std::endl;
			break ;
		}
		else {
			std::cout << "Invalid command. Please try again." << std::endl;
			continue ;
		}
	}
	return 0;
}
