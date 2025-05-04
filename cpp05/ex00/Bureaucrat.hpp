#pragma once

# include <iostream>
# include <stdexcept>
# include <string>

# define MAX_GRADE	1
# define MIN_GRADE	150

using std::cout;
using std::ostream;
using std::string;
using std::exception;

class Bureaucrat
{
	private:
		const string	name;
		int				grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator =(const Bureaucrat& other);
		~Bureaucrat();

		const string&	getName() const;
		int				getGrade() const;

		void	incrementGrade(int change = 1);
		void	decrementGrade(int change = 1);

		class GradeTooLowException: public exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public exception
		{
			virtual const char*	what() const throw();
		};
};

ostream&	operator << (ostream &output, const Bureaucrat& bureaucrat);
