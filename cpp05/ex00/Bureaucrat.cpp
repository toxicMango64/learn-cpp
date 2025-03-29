#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(string name, int grade) : _name(name) {
	cout << "[C] Bureaucrat base constructor called." << "\n";
	if (grade < GradeTooHigh)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > GradeTooLow)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat() {
	cout << "[C] Bureaucrat default constructor called." << "\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()) {
	cout << "[C] Bureaucrat copy constructor called." << "\n";
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	cout << "[D] Bureaucrat default destructor called." << "\n";
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &rSym) {
	if (this != &rSym) {
		this->_grade = rSym._grade;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym) {
	o << rSym.getName() << ", bureaucrat grade : " << rSym.getGrade();
	return o;
}

string	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

void	Bureaucrat::increment() {
	if (this->_grade > GradeTooHigh)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrement() {
	if (this->_grade < GradeTooLow)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char *	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("A bureaucrat can't have a grade greater than 1.");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("A bureaucrat can't have a grade lower than 150.");
}
