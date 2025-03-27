#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int	main() {
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "string adress : " << &str << "\n";
	cout << "string ptr adress : " << stringPTR << "\n";
	cout << "string ref adress : " << &stringREF << "\n";

	cout << "string value : " << str << "\n";
	cout << "string ptr value : " << *stringPTR << "\n";
	cout << "string ref value : " << stringREF << "\n";
}
