// main.cpp
#include "phonebook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

int	main(void) {
	Phonebook	phonebook;
	std::string	input;

	std::cout << "Welcome to the Phonebook!" << std::endl << std::endl;
	while (1) {
		std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "\nPlease enter a command: ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			std::cout << GREEN << "\nBye!" << RESET << std::endl;
			break ;
		}
		else if (input == "ADD") {
			phonebook.addContact();
		}
		else if (input == "SEARCH") {
			phonebook.searchContact();
		}
		else {
			std::cout << RED << "\nInvalid command. Please try again.\n" << RESET << std::endl;
		}
	}
	return (0);
}

int main() {
    app::PhoneBook phoneBook;
    std::string command;
    bool exitProgram = false;

    std::system("clear");

    while (!exitProgram) {
        std::cout << INFO_COLOR << "Enter command (ADD, SEARCH, EXIT): " << RESET;

        if (!(std::cin >> command)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << ERROR_COLOR << "\nEnd of input reached. Exiting the program.\n" << RESET;
            exitProgram = true;
        } else if (command == "ADD" || command == "1") {
            app::Contact contact;
            std::string first, last, nick, phone, secret;

            std::cout << QUESTION_COLOR << "First Name: " << RESET; std::cin >> first;
            std::cout << QUESTION_COLOR << "Last Name: " << RESET; std::cin >> last;
            std::cout << QUESTION_COLOR << "Nickname: " << RESET; std::cin >> nick;
            std::cout << QUESTION_COLOR << "Phone Number: " << RESET; std::cin >> phone;
            std::cout << QUESTION_COLOR << "Darkest Secret: " << RESET; std::cin >> secret;

            contact.setContact(first, last, nick, phone, secret);
            phoneBook.addContact(contact);
        } else if (command == "SEARCH" || command == "2") {
            phoneBook.searchContacts();
        } else if (command == "EXIT" || command == "3") {
            std::cout << "Exiting the phonebook. Contacts will be lost forever!" << std::endl;
            exitProgram = true;
        } else {
            std::cout << ERROR_COLOR << "Invalid command! Please enter ADD, SEARCH, or EXIT.\n" << RESET;
        }
    }

    return 0;
}
