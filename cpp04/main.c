#include <stdio.h>

int main(int ac, char **av) {
	if (2 > ac) {
		return (1);
	}

	char *arg1 = av[1];

	printf("%s\n", av[1]);
	printf(av[1]);

	return (0);
}
