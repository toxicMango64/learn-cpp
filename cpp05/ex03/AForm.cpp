#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


AForm::AForm(): isSigned(0), gradeSign(0), gradeExec(0)
{
	cout << "Default AForm got created" << "\n";
}

AForm::AForm(const std::string& name, const std::string& target, int gradeSign, int gradeExec): name(name), isSigned(false), target(target), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else if (gradeSign < MAX_GRADE)
		throw AForm::GradeTooHighException();

	if (gradeExec > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else if (gradeExec < MAX_GRADE)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& copy): name(copy.name), isSigned(false), target(copy.target),gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{
	cout << "AForm of " << copy.name << " got copied as " << this->getName() << "\n";
}

AForm&	AForm::operator =(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm()
{

}

const std::string&	AForm::getName() const
{
	return name;
}

bool	AForm::getSigned() const
{
	return isSigned;
}

int	AForm::getGradeSign() const
{
	return gradeSign;
}

int	AForm::getGradeExec() const
{
	return gradeExec;
}

const std::string&	AForm::getTarget() const
{
	return target;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (isSigned)
		throw AlreadySignedException();
	else if (gradeSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned)
		throw ExecuteUnsignedException();
	if (gradeExec < executor.getGrade())
		throw GradeTooLowException();
	executeConcrete();
}

AForm *AForm::makeForm(const std::string &form_type, const std::string &target)
{
	if (form_type == "shrubbery creation")
		return new ShrubberyCreationForm(target);
	else if (form_type == "robotomy request")
		return new RobotomyRequestForm(target);
	else if (form_type == "presidential pardon")
		return new PresidentialPardonForm(target);
	else
		throw std::invalid_argument("Unknown form type: " + form_type);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low!";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high!";
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return "AForm couldn’t sign a Aform twice!";
}

const char*	AForm::ExecuteUnsignedException::what() const throw()
{
	return "Form couldn’t execute unsigned form!";
}

char const	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

char const	*AForm::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
}

std::ostream&	operator<<(std::ostream &output, const AForm& Aform)
{
	output	<< "AForm name is: " << Aform.getName() << ",target is: "<<Aform.getTarget()<< ", signed: "<< Aform.getSigned() << ", grade to sign " << Aform.getGradeSign() << ", grade to execute " << Aform.getGradeExec() << "\n";
	return output;
}
