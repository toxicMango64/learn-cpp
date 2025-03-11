#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	Cat			*cat = new Cat();
	Dog			*dog = new Dog();
	WrongAnimal	*unknown = new WrongAnimal();

	cout << cat->getType() << " " << endl;
	cout << dog->getType() << " " << endl;
	cout << unknown->getType() << " " << endl;

	cat->makeSound();
	dog->makeSound();
	unknown->makeSound();
	delete unknown;

	unknown = new WrongCat();
	unknown->makeSound();
	delete cat;
	delete dog;
	return (0);
}

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	cout << j->getType() << " " << endl;
// 	cout << i->getType() << " " << endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	...
// 	return 0;
// }