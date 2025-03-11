#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int	main() {
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "string adress : " << &str << endl;
	cout << "string ptr adress : " << stringPTR << endl;
	cout << "string ref adress : " << &stringREF << endl;

	cout << "string value : " << str << endl;
	cout << "string ptr value : " << *stringPTR << endl;
	cout << "string ref value : " << stringREF << endl;
}
