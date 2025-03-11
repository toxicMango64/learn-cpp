#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
	index = 0;
	contactCount = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

void	Phonebook::addContact(void) {
	try {
		contacts[index % MAX_CAPACITY].setContact();
		if (contactCount < MAX_CAPACITY)
			contactCount++;
		else
			std::cout << YELLOW << "phonebook at MAX capacity. Oldest contact replaced." << RESET << std::endl;
		index++;
	}
	catch (const std::runtime_error &e) {
		std::cout << RED << "Unable to add contact: Verify the information and try again." << e.what() << RESET << std::endl;
	}
	return ;
}

void	print_field(string field) {
    string	truncatedText;
	int 		padding;
	
    if (field.length() > 10) {
        truncatedText = field.substr(0, 9) + ".";
    } 
	else {
        truncatedText = field;
    }
    padding = 10 - truncatedText.length();
    for (int i = 0; i < padding; ++i) {
        std::cout << " ";
    }
    std::cout << truncatedText;
	return ;
}

void	ft_print_header(string index, string first_name, string last_name, string nickname) {
	
	cout << "|";
	print_field(index);
	cout << "|";
	print_field(first_name);
	cout << "|";
	print_field(last_name);
	cout << "|";
	print_field(nickname);
	cout << "|" << endl;
	return ;
}

void	Phonebook::searchContact(void) {
	std::stringstream	ss;
	string 		input;
	
	// cout << "Index" << "First Name" << "Last Name" << "Nickname";
	ft_print_header("Index", "First Name", "Last Name", "Nickname");
	ft_print_header("----------", "----------", "----------", "----------");
	for (int i = 0; i < contactCount; i++) {
		ss.str("");
		ss << i;
		ft_print_header(ss.str(), contacts[i].getFirstName(), contacts[i].getLastName(), contacts[i].getNickname());
	}
	std::cout << std::endl;
	std::cout << "enter the index to view ";
	std::getline(std::cin, input);
	if (input.empty() && !std::cin.eof()) {
		// throw std::runtime_error("\nFailed to set the attribute.");
		// continue ;
		return ;
	}
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '7' && input[0] - '0' < contactCount)
		contacts[input[0] - '0'].printContact();
	else
		std::cout << RED << "\nError: Invalid index.\n" << RESET << std::endl;
	return ;
}
