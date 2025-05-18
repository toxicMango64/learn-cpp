#pragma once

# include "Form.hpp"
# include <iostream>
# include <stdexcept>
# include <string>

# define MIN_GRADE	150
# define MAX_GRADE	1

using std::string;
using std::ostream;
using std::exception;

class Form;
class Bureaucrat
{
	private:
		const string	name;
		int					grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator =(const Bureaucrat& other);
		~Bureaucrat();

		const string&	getName() const;
		int					getGrade() const;

		void	incrementGrade(int change = 1);
		void	decrementGrade(int change = 1);
		void	signForm(Form& form) const;

		class GradeTooLowException: public exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public exception
		{
			virtual const char*	what() const throw();
		};
};

ostream&	operator<<(ostream &output, const Bureaucrat& bureaucrat);
