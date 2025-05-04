
#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		emma;
	AForm		*form;
	Bureaucrat	bureau_1("bureau_1", 50);

	try
	{
		form = emma.makeForm("robotomy request", "Alice");
		delete form;
		form = emma.makeForm("shrubbery creation", "Charlie");
		delete form;
		form = emma.makeForm("presidential pardon", "David");
		delete form;
		form = emma.makeForm("random request", "Elisa");
		delete form;
	}
	catch (std::exception &e)
	{
		cout << "Caught exception: " << e.what() << "\n";
	}

	cout << "------------------------------------" << "\n";
	form = emma.makeForm("robotomy request", "Bender");
	delete form;
	cout << "------------------------------------" << "\n";
	form = emma.makeForm("shrubbery creation", "Fred");
	form->beSigned(bureau_1);
	bureau_1.executeForm(*form);
	delete form;
	cout << "------------------------------------" << "\n";
	form = emma.makeForm("presidential pardon", "Georgia");
	bureau_1.signForm(*form);
	bureau_1.executeForm(*form);
	cout << "------------------------------------" << "\n";
	delete form;
}
