#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{
	cout << "Default RobotomyRequestForm got created" << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", target, 72, 45)
{
	cout << "RobotomyRequestForm got created with the target: " << this->target << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
	*this = copy;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{

	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm got destroyed" << "\n";
}


void	RobotomyRequestForm::executeConcrete() const
{
	cout << "*** DRILLING NOISES ***" << "\n" << target;
	srand(time(NULL));
	if (rand() % 2)
		cout << " has been robotimized successfully!" << "\n";
	else
		cout << " robotomy failed!" << "\n";
}
