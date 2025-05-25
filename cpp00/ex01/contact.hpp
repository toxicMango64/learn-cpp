#pragma once

# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <cctype>

using std::string;
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";

class Contact {
private:
	string	_firstName;
	string	_lastName;
	string	_nickname;
	string	_phoneNumber;
	string	_darkestSecret;

public:
	Contact();
	~Contact();
	void		setFirstName(string firstName);
	void		setLastName(string lastName);
	void		setNickname(string nickname);
	void		setPhoneNumber(string phoneNumber);
	void		setDarkestSecret(string darkestSecret);
	string		getFirstName();
	string		getLastName();
	string		getNickname();
	string		getPhoneNumber();
	string		getDarkestSecret();
	void		setContact();
	void		setInput(const string& prompt, void (Contact::*setter)(const string));
	void		clearInput(void);
	void		printContact();
};
