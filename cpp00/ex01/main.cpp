#include "phonebook.hpp"

int main() {
	Phonebook phonebook;
	std::string choice;

	std::system("clear");
	std::cout << "Welcome to the Phonebook!\n"
			  << '\n';

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";

		if (!std::getline(std::cin, choice)) {
			if (std::cin.eof()) {
				std::cout << "Exiting the Phonebook. Goodbye!" << '\n';
				exit (1);
			} else {
				std::cerr << "Error reading input." << '\n';
				exit (1);
			}
		}

		if (choice.empty()) {
			cout << "here" << "\n";
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
			std::cout << "Exiting the Phonebook. Goodbye!" << '\n';
			break ;
		}
		else {
			std::cout << "Invalid command. Please try again." << '\n';
			continue ;
		}
	}
	return 0;
}
