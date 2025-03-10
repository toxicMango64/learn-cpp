// Contact.cpp
#include "contact.hpp"
#include "phonebook.hpp"

namespace app {

    void Contact::setContact(const std::string& first, const std::string& last, const std::string& nick,
                             const std::string& phone, const std::string& secret) {
        if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty()) {
            std::cout << "Error: All fields must be non-empty!" << std::endl;
            return;
        }

        firstName = first;
        lastName = last;
        nickname = nick;
        phoneNumber = phone;
        darkestSecret = secret;
    }

    void Contact::displaySummary(int index) const {
        const int fieldWidth = 10;
        std::string formattedFirstName = (firstName.size() > fieldWidth) ? firstName.substr(0, fieldWidth - 1) + "." : firstName;
        std::string formattedLastName = (lastName.size() > fieldWidth) ? lastName.substr(0, fieldWidth - 1) + "." : lastName;
        std::string formattedNickname = (nickname.size() > fieldWidth) ? nickname.substr(0, fieldWidth - 1) + "." : nickname;

        std::cout << std::setw(fieldWidth) << index << "|"
                  << std::setw(fieldWidth) << formattedFirstName
                  << "|" << std::setw(fieldWidth) << formattedLastName
                  << "|" << std::setw(fieldWidth) << formattedNickname
                  << std::endl;
    }

    void Contact::displayDetails() const {
        std::cout << INFO_COLOR  << "First Name: " << firstName << RESET << std::endl;
        std::cout << INFO_COLOR  << "Last Name: " << lastName << RESET << std::endl;
        std::cout << INFO_COLOR  << "Nickname: " << nickname << RESET << std::endl;
        std::cout << INFO_COLOR  << "Phone Number: " << phoneNumber << RESET << std::endl;
        std::cout << INFO_COLOR  << "Darkest Secret: " << darkestSecret << RESET << std::endl;
    }

}
