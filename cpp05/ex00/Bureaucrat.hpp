#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat {
	public:
		Bureaucrat(string name, int grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const &rSym);
		string			getName() const;
		int				getGrade() const;

		void			promote();
		void			demote();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
	private:
		string const	_name;
		int				_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym);

#endif