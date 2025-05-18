#include "./Base.hpp"
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"

void	identify(Base * p) {
	if (dynamic_cast<A *>(p))
		std::cout << "The pointer is a A type." << "\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "The pointer is a B type." << "\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "The pointer is a C type." << "\n";
}

void	identify(Base & p) {
	try {
		A &	a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "The reference is a A type." << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << "dynamic_cast to A failed: " << e.what() << "\n";
	}
	try {
		B &	b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "The reference is a B type." << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << "dynamic_cast to B failed: " << e.what() << "\n";
	}
	try {
		C &	c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "The reference is a C type." << "\n";
	}
	catch(const std::exception& e) {
		std::cerr << "dynamic_cast to C failed: " << e.what() << "\n";
	}
}

Base *	generate() {
	Base *	ptr;
	
	int n = rand() % 3;
	
	if (n == 2) {
		ptr = new A;
		std::cout << "New A created." << "\n";
	}
	else if (n == 1) {
		ptr = new B;
		std::cout << "New B created." << "\n";
	}
	else if (n == 0) {
		ptr = new C;
		std::cout << "New C created." << "\n";
	}
	return ptr;
}

int	main() {
	srand(time(NULL));
	Base *	ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;

	return 0;
}
