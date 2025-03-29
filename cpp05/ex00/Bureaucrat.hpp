#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>
#include <cstdint>

using std::string;
using std::cout;
using std::endl;

class Bureaucrat {
	enum e_grade : std::int16_t {
		GradeTooHigh = 1,
		GradeTooLow = 150
	};
	private:
		string const	_name;
		int				_grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(string name, int grade);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat const &rSym);
		string		getName() const;
		int			getGrade() const;

		void		increment();
		void		decrement();

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
};

std::ostream &	operator<<(std::ostream &o, Bureaucrat const &rSym);

#endif
