#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main() {
	Cat		Gattino;
	Dog		Rex;

	cout << Gattino.getType() << " " << endl;
	cout << Rex.getType() << " " << endl;

	Rex.makeSound();
	Gattino.think();
	Rex.think();

	return 0;
}
