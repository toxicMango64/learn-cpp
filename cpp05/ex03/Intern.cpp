#include "Intern.hpp"

Intern::Intern(void)
{
	cout << "Default constructor of Intern got created " <<"\n";
}

Intern::Intern(Intern const &copy)
{
	cout << "Copy constructor of Intern got created " <<"\n";
	*this = copy;
}

Intern const	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern(void)
{
	cout << "Intern got destroyed" << "\n";
}


AForm	*Intern::makeForm(const std::string &form_name, const std::string &target)
{
	AForm	*form;

	form = AForm::makeForm(form_name, target);
	if (!form)
		throw (AForm::InvalidFormException());
	else
		cout << "Intern creates form of " << form->getName() << "\n";
	return (form);
}
