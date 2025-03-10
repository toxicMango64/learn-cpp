// PhoneBook.h
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

/* **************************************************************************** */
/* ANSI escape codes for text color */
/* **************************************************************************** */
const std::string GB        =	"\033[42m"
const std::string RESET		=	"\033[0m"
const std::string RED		=	"\033[0;31m"
const std::string WHITE		=	"\033[0;97m"
const std::string BLUE		=	"\033[0;34m"
const std::string GRAY		=	"\033[0;90m"
const std::string CYAN		=	"\033[0;36m"
const std::string BLACK		=	"\033[0;30m"
const std::string GREEN		=	"\033[0;32m"
const std::string YELLOW	=	"\033[0;33m"
const std::string MAGENTA	=	"\033[0;35m"
const std::string BLUE		=	"\033[0;36m"
const std::string L_RED		=	"\033[0;91m"
const std::string L_GRAY	=	"\033[0;37m"
const std::string L_BLUE	=	"\033[0;94m"
const std::string L_CYAN	=	"\033[0;96m"
const std::string L_GREEN	=	"\033[0;92m"
const std::string L_YELLOW	=	"\033[0;93m"
const std::string L_MAGENTA	=	"\033[0;95m"
const std::string C			=	"\033[38;5;"
const std::string O			=	"72"
const std::string L			=	"m"
const std::string ERROR_COLOR = "\033[38;2;255;76;76m"; // Error messages (Red)
const std::string INFO_COLOR = "\033[38;2;76;140;255m";  // Info messages (Blue)
const std::string QUESTION_COLOR = "\033[38;2;255;165;0m"; // Question messages (Orange)
const std::string RESET = "\033[0m";                      // Reset to default color


//// Define a simple struct to represent colors
//struct Color {
//    int r;  // Red component
//    int g;  // Green component
//    int b;  // Blue component
//
//    // Constructor for convenience
//    Color(int red, int green, int blue) : r(red), g(green), b(blue) {}
//};
//
//// Define the colors from the palette
//Color softBlue(163, 193, 218);   // #A3C1DA
//Color warmYellow(246, 229, 141); // #F6E58D
//Color mutedGreen(184, 225, 179); // #B8E1B3
//Color coral(255, 111, 97);       // #FF6F61
//Color gray(176, 179, 184);       // #B0B3B8
//// Define colors for messages
//Color errorColor(255, 76, 76);    // Error Messages: #FF4C4C
//Color infoColor(76, 140, 255);     // Info Messages: #4C8CFF
//Color questionColor(255, 165, 0);  // Question Messages: #FFA500

namespace app {

    class PhoneBook {
    private:
        Contact contacts[8];
        int currentIndex;

    public:
        PhoneBook();

        void addContact(const Contact &contact);

        void searchContacts() const;
    };

}

#endif
