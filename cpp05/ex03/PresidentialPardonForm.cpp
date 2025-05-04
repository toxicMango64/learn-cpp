#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{
	cout << "Default PresidentialPardonForm got created" << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", target, 25, 5)
{
	cout << "PresidentialPardonForm got created with the target: " << this->target << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	*this = other;
}
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{

	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm got destroyed" << "\n";
}


void	PresidentialPardonForm::executeConcrete() const
{
	cout << target << " has been pardoned by Zaphod Beeblebrox." << "\n";
}
