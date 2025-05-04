#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{

	cout<<"\n";
	Bureaucrat	bureau_1("bureau_1", 1);
	Bureaucrat	bureau_2("bureau_2", 42);
	cout << bureau_1 << bureau_2;

	try
	{
		{
			cout<<"\n"<<"Shrubbery creation: "<<"\n";
			ShrubberyCreationForm form("home");
			cout << form;
			bureau_1.signForm(form);
			bureau_1.executeForm(form);
		}
		{
			cout<<"\n"<<"Robotomy request: "<<"\n";
			RobotomyRequestForm form("Bender");
			cout << form;
			bureau_1.signForm(form);
			bureau_1.executeForm(form);
		}
		{
			cout<<"\n"<<"Presidential pardon: "<<"\n";
			PresidentialPardonForm form("lrocca");
			cout << form;
			bureau_1.signForm(form);
			bureau_1.executeForm(form);
		}
		PresidentialPardonForm form("lrocca");
		{
			cout<<"\n"<<"Execute unsigned form: "<<"\n";
			cout << form;
			bureau_1.executeForm(form);
		}
		{
			cout<<"\n"<<"Too low to execute: "<<"\n";
			bureau_1.signForm(form);
			bureau_2.executeForm(form);
		}
	}
	catch (std::exception& e)
	{
		cout << "Error: " << e.what() << "\n";
	}

}
