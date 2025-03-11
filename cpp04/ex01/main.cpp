#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
// #include "gsl/gsl.h"
// #include <new>
// #include <exception>

int	main() {
	Animal	*array[100];
	int		i = 0;

	while (i < 50)
		array[i++] = new Dog();
	while (i < 100)
		array[i++] = new Cat();

	array[4]->makeSound();
	array[72]->makeSound();

	// array[4]->getType().makeSound();
	// array[72]->getType().makeSound();

	for (i = 0; i < 100; i++)
        delete array[i];
		
	return 0;
}

// class CustomAllocator {
// public:
// 	static int allocationCount;

// 	static void* allocate(size_t size) {
// 		if (size == 0) {
// 			throw std::bad_alloc();
// 		}
// 		void* ptr = ::operator new(size);
// 		if (!ptr) {
// 			throw std::bad_alloc();
// 		}
// 		allocationCount++;
// 		return ptr;
// 	}

// 	static void deallocate(void* ptr) {
// 		if (ptr) {
// 			::operator delete(ptr);
// 		}
// 	}
// };

// int CustomAllocator::allocationCount = 0;

// int main() {
// 	const int arraySize = 10;
// 	Animal* array[arraySize];
// 	int i = 0;

// 	try {
// 		// Allocate Dog objects
// 		while (i < arraySize / 2) {
// 			array[i++] = static_cast<Animal*>(CustomAllocator::allocate(sizeof(Dog)));
// 			new (array[i - 1]) Dog();
// 		}
		
// 		// Allocate Cat objects
// 		while (i < arraySize) {
// 			array[i++] = static_cast<Animal*>(CustomAllocator::allocate(sizeof(Cat)));
// 			new (array[i - 1]) Cat();
// 		}

// 		array[9]->makeSound(); /* add more if you want */
// 		array[2]->makeSound();
// 	} catch (const std::bad_alloc& e) {
// 		std::cerr << "Memory allocation failed: " << e.what() << '\n';
// 		for (int j = 0; j < i; j++) {
// 			CustomAllocator::deallocate(array[j]); /* deallocate method */
// 		}
// 		return 1;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception caught: " << e.what() << '\n';
// 		for (int j = 0; j < i; j++) {
// 			CustomAllocator::deallocate(array[j]); /* custom deallocate method */
// 		}
// 		return 1;
// 	}

// 	for (int j = 0; j < arraySize; j++) {
// 		CustomAllocator::deallocate(array[j]); /* custom deallocate method */
// 	}

// 	return 0;
// }
