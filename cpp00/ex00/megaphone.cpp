#include <iostream>

using std::cout;

int  main(int ac, char **av) {
	if (ac == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	} else {
		int offset = 0;
		while (++offset < ac) {
			int index = -1;
			while (av[offset][++index]) {
				if (32 == av[offset][index]) {
					cout << (char) av[offset][index];
				}
				else {
					cout << (char) std::toupper(av[offset][index]);
				}
			}
		}
	}
	cout << std::endl;
	return (0);
}
