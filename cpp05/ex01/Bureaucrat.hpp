#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>

using std::string;

class Bureaucrat {
	private:
		string const	_name;
		int				_grade;
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
		void			signForm(string name, bool sign);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &rSym);

#endif