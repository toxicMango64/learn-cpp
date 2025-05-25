#include "contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

void	Contact::setFirstName(string firstName) {
	string::iterator it;
	bool isAlpha = true;

	if (firstName.empty()) {
		throw std::invalid_argument("Empty first name.");
	}	
	for (it = firstName.begin(); it < firstName.end(); ++it) {
		if (!std::isalpha(*it)) {
			isAlpha = false;
			break ;
		}
	}
	if (!isAlpha) {
		throw std::invalid_argument("Invalid first name.");
	}
	_firstName = firstName;
}

void	Contact::setLastName(string lastName) {
	string::iterator it;
	bool isAlpha = true;

	if (lastName.empty()) {
		throw std::invalid_argument("Empty last name.");
	}	
	for (it = lastName.begin(); it < lastName.end(); ++it) {
		if (!std::isalpha(*it)) {
			isAlpha = false;
			break ;
		}
	}
	if (!isAlpha) {
		throw std::invalid_argument("Invalid last name.");
	}
	_lastName = lastName;
};

void	Contact::setNickname(string nickname) {
	if (nickname.empty()) {
		throw std::invalid_argument("Empty nickname.");
	}
	for (std::size_t i = 0; i < nickname.size(); ++i) {
		char ch = nickname[i];
		if (!std::isalnum(ch) && ch != '-' && ch != '_' && ch != '.') {
			throw std::invalid_argument("Invalid nickname.");
		}
	}
	_nickname = nickname;
};

void	Contact::setPhoneNumber(string phoneNumber) {
	if (phoneNumber.empty()) {
		throw std::invalid_argument("Empty phone number.");
	}	
	for (std::size_t i = 0; i < phoneNumber.size(); ++i) {
		char digit = phoneNumber[i];
		if (!std::isdigit(digit)) {
			throw std::invalid_argument("Invalid phone number.");
		}
	_phoneNumber = phoneNumber;
	}
};

void	Contact::setDarkestSecret(string darkestSecret) {
	if (darkestSecret.empty()) {
		throw std::invalid_argument("Empty darkest secret.");
	}
	_darkestSecret = darkestSecret;
};

// Getters
string	Contact::getFirstName(void) {
	return (_firstName);
};

string	Contact::getLastName(void) {
	return (_lastName);
};

string	Contact::getNickname(void) {
	return (_nickname);
};

string	Contact::getPhoneNumber(void) {
	return (_phoneNumber);
};

string	Contact::getDarkestSecret(void) {
	return (_darkestSecret);
};

void Contact::setContact(void) {
	try {
		setInput("\tEnter first name: ", &Contact::setFirstName);
		setInput("\tEnter last name: ", &Contact::setLastName);
		setInput("\tEnter nickname: ", &Contact::setNickname);
		setInput("\tEnter phone number: ", &Contact::setPhoneNumber);
		setInput("\tEnter darkest secret: ", &Contact::setDarkestSecret);
		std::cout << GREEN << "Contact added successfully!\n" << RESET << std::endl;
	} catch (const std::exception& e) {
		clearInput();
		throw;
	}
	return;
}

void Contact::setInput(const string& prompt, void (Contact::*setter)(const string)) {
	string value;
	bool isValid = false;

	for (int i = 0; i < 3 && !isValid; i++) {
		std::cout << GREEN << prompt << RESET;
		if (!(std::cin >> value)) {
			if (std::cin.eof()) {
				std::cout << "Exiting the Phonebook. Goodbye!" << std::endl;
				exit(0);
			} else {
				std::cerr << "Error reading input." << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				continue ;
			}
		}
		if (value.empty()) {
			std::cerr << "Error reading input." << std::endl;
			break ;
		}
		try {
			(this->*setter)(value);
			isValid = true;
		} catch (const std::exception& e) {
			std::cout << YELLOW << "Invalid input. Please try again." << RESET << std::endl;
		}
	}
	if (!isValid) {
		throw std::runtime_error("\nFailed to set the attribute after three attempts.");
	}
	return;
}

void	Contact::clearInput(void) {
	_firstName.clear();
	_lastName.clear();
	_nickname.clear();
	_phoneNumber.clear();
	_darkestSecret.clear();
}

void	Contact::printContact(void) {
	std::cout << std::endl;
	std::cout << "First name: " << this->getFirstName() << std::endl;
	std::cout << "Last name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickname() << std::endl;
	std::cout << "Phone number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
