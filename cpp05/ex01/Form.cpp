#include "Form.hpp"

Form::Form(): isSigned(0), gradeSign(0), gradeExec(0)
{

}

Form::Form(const string& name, int gradeSign, int gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign > MIN_GRADE)
		throw Form::GradeTooLowException();
	else if (gradeSign < MAX_GRADE)
		throw Form::GradeTooHighException();

	if (gradeExec > MIN_GRADE)
		throw Form::GradeTooLowException();
	else if (gradeExec < MAX_GRADE)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& copy): name(copy.name + "_copy"), isSigned(false), gradeSign(copy.gradeSign), gradeExec(copy.gradeExec)
{

}


Form&	Form::operator =(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form()
{

}

const string&	Form::getName() const
{
	return name;
}

bool	Form::getSigned() const
{
	return isSigned;
}

int	Form::getGradeSign() const
{
	return gradeSign;
}

int	Form::getGradeExec() const
{
	return gradeExec;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (isSigned)
		throw AlreadySignedException();
	else if (gradeSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	isSigned = true;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return "Form couldn’t sign a form twice!";
}
ostream&	operator<<(ostream &output, const Form& form)
{
	output	<< "Form name is: " << form.getName() << ", signed: "<< form.getSigned() << ", grade to sign " << form.getGradeSign()
		<< ", grade to execute " << form.getGradeExec() << "\n";
	return output;
}
