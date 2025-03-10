// Contact.h
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

namespace app {

    class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        void setContact(const std::string& first, const std::string& last, const std::string& nick,
                        const std::string& phone, const std::string& secret);

        void displaySummary(int index) const;

        void displayDetails() const;
    };

}

#endif
