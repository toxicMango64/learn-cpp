#pragma once

# include "Bureaucrat.hpp"
# include <iomanip>
# include <stdexcept>
# include <string>

using std::cout;
using std::string;
using std::exception;
using std::ostream;

class Bureaucrat;

class Form
{
	private:
		const		string name;
		bool		isSigned;
		const int	gradeSign;
		const int	gradeExec;

	public:
		Form();
		Form(const string& name, int gradeSign, int gradeExec);
		Form(const Form& other);
		Form&	operator =(const Form& other);
		~Form();

		const string&	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException: public exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public exception
		{
			virtual const char*	what() const throw();
		};

		class AlreadySignedException: public exception
		{
			virtual const char*	what() const throw();
		};
};

ostream&	operator<<(ostream &output, const Form& form);
