#include "Bureaucrat.hpp"

int	main()
{

	cout<<"\n"<<"---------- Base Case ----------------------"<<"\n";
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

    cout << "\n" << "---------- Copy Constructor Case ----------" << "\n";
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

	cout<<"\n"<<"---------- Increment Case -----------------"<<"\n";
	try
	{
		Bureaucrat	bureau_1("bureau_3", 12);
		cout << bureau_1;
		bureau_1.incrementGrade(10);
		cout << bureau_1;
		bureau_1.incrementGrade();
		cout << bureau_1;
		bureau_1.incrementGrade();
		cout << bureau_1;
	}
	catch (exception& e)
	{
		cout << "Error(3): " << e.what() << "\n";
	}

//-------------------------------------------------------------------------------------------------

	cout<<"\n"<<"---------- Decrement Case -----------------"<<"\n";
	try
	{
		Bureaucrat	bureau_1("bureau_4", 139);
		cout << bureau_1;
		bureau_1.decrementGrade(10);
		cout << bureau_1;
		bureau_1.decrementGrade();
		cout << bureau_1;
		bureau_1.decrementGrade();
		cout << bureau_1;
	}
	catch (exception& e)
	{
		cout << "Error(4): " << e.what() << "\n";
	}

}
