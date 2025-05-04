
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{

	cout<<"\n"<<"---------- Base Case --------------------------------------------------------------------------"<<"\n";
	try
	{
		Bureaucrat();
		cout <<"----------" << "\n";
		Bureaucrat	bureau_1("bureau_1", 1);
		cout << bureau_1;
	}
	catch (exception& e)
	{
		cout << "Error(0): " << e.what() << "\n";
	}
	cout <<"----------" << "\n";
	try
	{
		Bureaucrat	bureau_2("bureau_2", -42);
		cout << bureau_2;
	}
	catch (exception& e)
	{
		cout << "Error(1): " << e.what() << "\n";
	}

	try
	{
		Bureaucrat	bureau_2("bureau_2", 4242);
		cout << bureau_2;
	}
	catch (exception& e)
	{
		cout << "Error(2): " << e.what() << "\n";
	}

//-------------------------------------------------------------------------------------------------

    cout << "\n" << "---------- Copy Constructor Case ----------------------------------------------------------------" << "\n";
    try
    {
        Bureaucrat original("original", 50);
        cout << original;

        Bureaucrat copy(original);
        cout << copy;
    }
    catch (exception& e)
    {
        cout << "Error: " << e.what() << "\n";
    }
	//In C++, local objects are destroyed in the reverse order of their creation.
//-------------------------------------------------------------------------------------------------

	cout<<"\n"<<"---------- Increment Case -----------------------------------------------------------------------"<<"\n";
	try
	{
		Bureaucrat	bureau_3("bureau_3", 12);
		cout << bureau_3;
		bureau_3.incrementGrade(10);
		cout << bureau_3;
		bureau_3.incrementGrade();
		cout << bureau_3;
		bureau_3.incrementGrade();
		cout << bureau_3;
	}
	catch (exception& e)
	{
		cout << "Error(3): " << e.what() << "\n";
	}

//-------------------------------------------------------------------------------------------------

	cout<<"\n"<<"---------- Decrement Case -----------------------------------------------------------------------"<<"\n";
	try
	{
		Bureaucrat	bureau_4("bureau_4", 139);
		cout << bureau_4;
		bureau_4.decrementGrade(10);
		cout << bureau_4;
		bureau_4.decrementGrade();
		cout << bureau_4;
		bureau_4.decrementGrade();
		cout << bureau_4;
	}
	catch (exception& e)
	{
		cout << "Error(4): " << e.what() << "\n";
	}
//-------------------------------------------------------------------------------------------------
	cout<<"\n"<<"---------- Form Case 1 -------------------------------------------------------------------------"<<"\n";
	Bureaucrat	bureau_F1("bureau_F1", 42);
	cout << bureau_F1;
	try
	{
		Form	form_2("form_2", 4242, 1);
	}
	catch (exception& e)
	{
		cout << "Error(F1): " << e.what() << "\n";
	}
	try
	{
		Form	form_2("form_2", 42, 0);
	}
	catch (exception& e)
	{
		cout << "Error(F2): " << e.what() << "\n";
	}
//-------------------------------------------------------------------------------------------------
	cout<<"\n"<<"---------- Form Case 2 -------------------------------------------------------------------------"<<"\n";
	try
	{
		Form	form_2("form_2", 42, 42);
		Form	form_3("form_3", 1, 1);
		cout << "\n" << form_2 << form_3;
		cout<<"Sign two times: "<<"\n";
		bureau_F1.signForm(form_2);
		cout << form_2;
		bureau_F1.signForm(form_2);
		cout<<"Grade too low: "<<"\n";
		bureau_F1.signForm(form_3);
	}
	catch (exception& e)
	{
		cout << "Error(F3): " << e.what() << "\n";
	}

}
