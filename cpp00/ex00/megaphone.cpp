#include <iostream>

using std::cout;

int  main(int ac, char **av) {
	if (ac == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		int index = 0;
		while (++index < ac) {
			int offset = -1;
			while (av[index][++offset]) {
				cout << (char) std::toupper(av[index][offset]);
			}
			if ('\0' == av[index][offset]) { cout << " "; }
		}
	}
	cout << "\n";
	return (0);
}
