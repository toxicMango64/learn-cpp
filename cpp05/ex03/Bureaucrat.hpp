#pragma once

# include "AForm.hpp"
# include <iostream>
# include <stdexcept>
# include <string>

# define MIN_GRADE	150
# define MAX_GRADE	1

using std::cout;

class AForm;
class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator =(const Bureaucrat& other);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;

		void	incrementGrade(int change = 1);
		void	decrementGrade(int change = 1);
		void	signForm(AForm& form) const;
		void	executeForm(const AForm& form) const;

		class GradeTooLowException: public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &output, const Bureaucrat& bureaucrat);
