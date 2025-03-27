#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

using std::string;

class Form {
	private:
		string const	_name;
		bool			_signed;
		int const		_signGrade;
		int const		_executeGrade;
	public:
		Form(string name, int signGrade);
		Form();
		Form(Form const &src);
		~Form();

		Form &	operator=(Form const &rSym);
		string	getName() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExecuteGrade() const;

		void	beSigned(Bureaucrat &person);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
};

std::ostream &	operator<<(std::ostream & o, Form const &rSym);

#endif