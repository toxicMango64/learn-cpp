
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{

	std::cout  <<"\n"<<"---------- Base Case --------------------------------------------------------------------------"<<"\n";
	try
	{
		Bureaucrat();
		std::cout  <<"----------" << "\n";
		Bureaucrat	bureau_1("bureau_1", 1);
		std::cout  << bureau_1;
	}
	catch (exception& e)
	{
		std::cout  << "Error(0): " << e.what() << "\n";
	}
	std::cout  <<"----------" << "\n";
	try
	{
		Bureaucrat	bureau_2("bureau_2", -42);
		std::cout  << bureau_2;
	}
	catch (exception& e)
	{
		std::cout  << "Error(1): " << e.what() << "\n";
	}

	try
	{
		Bureaucrat	bureau_2("bureau_2", 4242);
		std::cout  << bureau_2;
	}
	catch (exception& e)
	{
		std::cout  << "Error(2): " << e.what() << "\n";
	}

//-------------------------------------------------------------------------------------------------

	std::cout << "\n" << "---------- Copy Constructor Case ----------------------------------------------------------------" << "\n";
	try
	{
		Bureaucrat original("original", 50);
		std::cout << original;

		Bureaucrat copy(original);
		std::cout << copy;
	}
	catch (exception& e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	//In C++, local objects are destroyed in the reverse order of their creation.
//-------------------------------------------------------------------------------------------------

	std::cout <<"\n"<<"---------- Increment Case -----------------------------------------------------------------------"<<"\n";
	try
	{
		Bureaucrat	bureau_3("bureau_3", 12);
		std::cout  << bureau_3;
		bureau_3.incrementGrade(10);
		std::cout  << bureau_3;
		bureau_3.incrementGrade();
		std::cout  << bureau_3;
		bureau_3.incrementGrade();
		std::cout  << bureau_3;
	}
	catch (exception& e)
	{
		std::cout  << "Error(3): " << e.what() << "\n";
	}

//-------------------------------------------------------------------------------------------------

	std::cout <<"\n"<<"---------- Decrement Case -----------------------------------------------------------------------"<<"\n";
	try
	{
		Bureaucrat	bureau_4("bureau_4", 139);
		std::cout  << bureau_4;
		bureau_4.decrementGrade(10);
		std::cout  << bureau_4;
		bureau_4.decrementGrade();
		std::cout  << bureau_4;
		bureau_4.decrementGrade();
		std::cout  << bureau_4;
	}
	catch (exception& e)
	{
		std::cout  << "Error(4): " << e.what() << "\n";
	}
//-------------------------------------------------------------------------------------------------
	std::cout <<"\n"<<"---------- Form Case 1 -------------------------------------------------------------------------"<<"\n";
	Bureaucrat	bureau_F1("bureau_F1", 42);
	std::cout  << bureau_F1;
	try
	{
		Form	form_2("form_2", 4242, 1);
	}
	catch (exception& e)
	{
		std::cout  << "Error(F1): " << e.what() << "\n";
	}
	try
	{
		Form	form_2("form_2", 42, 0);
	}
	catch (exception& e)
	{
		std::cout  << "Error(F2): " << e.what() << "\n";
	}
//-------------------------------------------------------------------------------------------------
	std::cout <<"\n"<<"---------- Form Case 2 -------------------------------------------------------------------------"<<"\n";
	try
	{
		Form	form_2("form_2", 42, 42);
		Form	form_3("form_3", 1, 1);
		std::cout  << "\n" << form_2 << form_3;
		std::cout <<"Sign two times: "<<"\n";
		bureau_F1.signForm(form_2);
		std::cout  << form_2;
		bureau_F1.signForm(form_2);
		std::cout <<"Grade too low: "<<"\n";
		bureau_F1.signForm(form_3);
	}
	catch (exception& e)
	{
		std::cout  << "Error(F3): " << e.what() << "\n";
	}

}
