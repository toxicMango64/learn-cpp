#pragma once

# include "Bureaucrat.hpp"
# include <iomanip>
# include <stdexcept>
# include <string>

// using std::cout;

class Bureaucrat;

class AForm
{
	protected:
		const std::string	name;
		bool				isSigned;
		const std::string	target;
		const int			gradeSign;
		const int			gradeExec;

		virtual void	executeConcrete() const = 0;

	public:
		AForm();
		AForm(const std::string& name, const std::string& target, int gradeSign, int gradeExec);
		AForm(const AForm& copy);
		AForm&	operator =(const AForm& other);
		virtual ~AForm();


		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		const std::string&	getTarget() const;
		void			beSigned(const Bureaucrat& bureaucrat);
		void			execute(const Bureaucrat& executor) const;
		static AForm		*makeForm(std::string const &form_type, std::string const &target);

		class GradeTooLowException: public std::exception
		{
			virtual const char*	what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			virtual const char*	what() const throw();
		};

		class AlreadySignedException: public std::exception
		{
			virtual const char*	what() const throw();
		};

		class ExecuteUnsignedException: public std::exception
		{
			virtual const char*	what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class InvalidFormException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

};

std::ostream&	operator<<(std::ostream &output, const AForm& Aform);
