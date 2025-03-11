#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat *	Donald = NULL;
	Bureaucrat *	Joe = NULL;

	try {
		Donald = new Bureaucrat("Donald", 5);
		Donald->promote();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	Joe = new Bureaucrat(*Donald);
	cout << *Donald << endl;
	cout << *Joe << endl;
	delete Donald;
}