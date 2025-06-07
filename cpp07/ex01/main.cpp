// Copyright [2025] <myousaf>
#include "./iter.hpp"

template<typename T>
void	iter(T *adress, int lenght, void (*fct)(const T& var)) {
	for (int i = 0; i < lenght; i++)
		fct(adress[i]);
}

template<typename T>
void	printValue(const T &val) {
	std::cout << val;
}

int	main() {
	char	array[] = {'a', 'b', 'c', 'd'};

	iter(array, 4, printValue<char>);
}