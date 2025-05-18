#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("default"), grade(150)
{
	std::cout  << "Bureaucrat got created as a " << this->getName() << " Bureaucrat, with grade of " << this->getGrade() << "\n";
}


Bureaucrat::Bureaucrat(const string& name, int grade): name(name), grade(grade)
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	else if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else
		std::cout << "Bureaucrat of " << this->name << " got created with grade of " << this->grade << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& original): name(original.name + "_copy"), grade(original.grade)
{
	std::cout  << "Bureaucrat of " << original.name << " got copied as " << this->getName() << "\n";
	*this = original;
}

Bureaucrat&	Bureaucrat::operator =(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout  << "Bureaucrat of " << this->name << " got destroyed" << "\n";
}

const string&	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade(int change)
{
	if (grade - change < MAX_GRADE)
		throw GradeTooHighException();
	grade -= change;
}

void	Bureaucrat::decrementGrade(int change)
{
	if (grade + change > MIN_GRADE)
		throw GradeTooLowException();
	grade += change;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high!";
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout  << name << " signed the form of " << form.getName() << "\n";
	}
	catch (exception& e)
	{
		std::cout  << name << " could not sign the form of " << form.getName() << " because " << e.what() << "\n";
	}
}

ostream&	operator<<(ostream &output, const Bureaucrat& bureaucrat)
{
	output	<< bureaucrat.getName() << ", bureaucrat grade "<< bureaucrat.getGrade() << "\n";
	return output;
}
