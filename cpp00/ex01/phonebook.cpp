// PhoneBook.cpp
#include "phonebook.hpp"
#include <iostream>

namespace app {

    PhoneBook::PhoneBook() : currentIndex(0) {}

    void PhoneBook::addContact(const Contact &contact) {
        contacts[currentIndex % 8] = contact;
        currentIndex++;
    }

    void PhoneBook::searchContacts() const {
        int i = 0;
        int numContacts = (currentIndex < 8) ? currentIndex : 8;

        while (i < numContacts) {
            contacts[i].displaySummary(i);
            i++;
        }

        int chosenIndex;
        std::cout << INFO_COLOR << "Enter the index of the contact to display: " << RESET;;
        std::cin >> chosenIndex;

        if (chosenIndex >= 0 && chosenIndex < numContacts) {
            contacts[chosenIndex].displayDetails();
        } else {
            std::cout << ERROR_COLOR << "Invalid index!" << RESET << std::endl;
        }
    }

}
