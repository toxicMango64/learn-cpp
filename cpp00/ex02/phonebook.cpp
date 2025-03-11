#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string nickname;

    Contact() {

    }

    void setContact() {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickname);
    }

    void printContact() const {
        std::cout << "First Name: " << firstName << ", Last Name: " << lastName << ", Nickname: " << nickname << std::endl;
    }
};


class Phonebook {
private:
    std::vector<Contact> contacts;
    size_t maxContacts; /* Maximum number of contacts, Declare without initialization */
    // std::vector<Contact> contacts;
    // const size_t maxContacts = 7;

public:
    Phonebook() : maxContacts(7) { // Initialize maxContacts in the initializer list
        contacts.reserve(maxContacts); // Reserve space for contacts
    }

    void addContact() {
        if (contacts.size() >= maxContacts) {
            std::cout << "Phonebook is full. The oldest contact has been replaced." << std::endl;
            contacts.erase(contacts.begin()); // Remove the oldest contact
        }

        Contact newContact;
        newContact.setContact();
        contacts.push_back(newContact);
    }

    void searchContact() {
        std::cout << "Enter the index of the contact you want to see: ";
        size_t index;
        std::cin >> index;
        std::cin.ignore(); // Clear the newline character from the input buffer

        if (index < 0 || index >= contacts.size()) {
            std::cerr << "Error: Invalid index." << std::endl;
            return;
        }

        contacts[index].printContact();
    }

    void printContacts() const {
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i << ": ";
            contacts[i].printContact();
        }
    }
};

int main() {
    Phonebook phonebook;
    std::string command;

    std::system("clear");
    std::cout << "Welcome to the Phonebook!" << std::endl;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}