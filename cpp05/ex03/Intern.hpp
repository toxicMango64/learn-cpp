#pragma once

#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		Intern const	&operator=(Intern const &copy);
		~Intern(void);

		AForm	*makeForm(std::string const &form_name, std::string const &target);
};
