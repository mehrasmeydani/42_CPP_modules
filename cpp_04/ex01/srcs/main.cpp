#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include <iostream>

int main()
{
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	// Dog testAnimal;
	// testAnimal = *dynamic_cast<const Dog*>(j);
	// std::cout << "After assignment testAnimal type: " << testAnimal.getType() << std::endl;
	// testAnimal.makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << "---------------------------------" << std::endl;
	}
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal* animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}
	}
	return 0;
}