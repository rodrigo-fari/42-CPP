/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:32:34 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/20 22:59:37 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << std::endl << "=============================================================| SCOPE 1 (Basics)" << std::endl;
	{
		msg("Animal Creation");
		const Animal* meta = new Animal();
		Animal* a = new Cat();
		Animal* b = new Dog();

		msg("Animal Sounds");
		meta->makeSound();
		a->makeSound();
		b->makeSound();

		msg("Animal Type");
		std::cout << meta->getType() << " " << std::endl;
		std::cout << a->getType() << " " << std::endl;
		std::cout << b->getType() << " " << std::endl;

		msg("Animals go to sleep");
		delete (meta);
		delete (a);
		delete (b);

		msg("End of Scope");
	}
	std::cout << "=============================================================| SCOPE 2 (Wrong Animal)" << std::endl;
	{
		msg("Wrong Animal Creation");
		const WrongAnimal* a = new WrongAnimal();
		const WrongAnimal* b = new WrongCat();

		msg("Wrong Animal Sounds");
		a->makeSound();
		b->makeSound();

		msg("Wrong Animal Type");
		std::cout << a->getType() << " " << std::endl;
		std::cout << b->getType() << " " << std::endl;

		msg("Wrong Animals go to sleep");
		delete(a);
		delete(b);

		msg("End fo Scope");
	}
	std::cout << "=============================================================| SCOPE 3 (DeepCopy)" << std::endl;
	{
		std::cout
			<< "\n\nFor simplicity, will only work with the ideas[0].\n"
			<< "This can be changed later during the evaluation if\n"
			<< "the evaluator want.\n\n";

		msg("Creating deepCat");
		Cat* deepCat = new Cat;

		msg("Setting deepCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	deepCat->getBrain()->setIdea(i, "Funny cat ideas.");
		// }
		deepCat->getBrain()->setIdea(0, "Funny cat ideas.");
		std::cout << "Idea set successfully\n";

		msg("Checking deepCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< deepCat->getBrain()->getIdea(0)
			<< "\n";

		msg("Creating deepCatTest");
		Cat* deepCatTest = deepCat;

		msg("Checking deepCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< deepCatTest->getBrain()->getIdea(0)
			<< "\n";
		
		msg("Changing deepCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	deepCatTest->getBrain()->setIdea(i, "Funny cat ideas.");
		// }
		deepCatTest->getBrain()->setIdea(0, "Angry cat ideas.");
		std::cout << "Idea changed successfully\n";

		msg("Checking new deepCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< deepCatTest->getBrain()->getIdea(0)
			<< "\n";

		msg("Checking original deepCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< deepCat->getBrain()->getIdea(0)
			<< "\n";

		msg("Cats go to sleep");
		delete deepCat;
		//delete deepCatTest; //! <-- This pointer somehow is linked to the deepCat one...
	}


	std::cout << "=============================================================| SCOPE 4 (Shallow Copy)" << std::endl;
	{
		std::cout
			<< "\n\nFor simplicity, will only work with the ideas[0].\n"
			<< "This can be changed later during the evaluation if\n"
			<< "the evaluator want.\n\n";

		msg("Creating shallowCat");
		Cat* shallowCat = new Cat;

		msg("Setting shallowCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	shallowCat->getBrain()->setIdea(i, "Funny cat ideas.");
		// }
		shallowCat->getBrain()->setIdea(0, "Funny cat ideas.");
		std::cout << "Idea set successfully\n";

		msg("Checking shallowCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< shallowCat->getBrain()->getIdea(0)
			<< "\n";

		msg("Creating shallowCatTest");
		Cat* shallowCatTest = new Cat(*shallowCat);

		msg("Checking shallowCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< shallowCatTest->getBrain()->getIdea(0)
			<< "\n";
		
		msg("Changing shallowCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	shallowCatTest->getBrain()->setIdea(i, "Funny cat ideas.");
		// }
		shallowCatTest->getBrain()->setIdea(0, "Angry cat ideas.");
		std::cout << "Idea changed successfully.\n";

		msg("Checking new shallowCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< shallowCatTest->getBrain()->getIdea(0)
			<< "\n";

		msg("Checking original shallowCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
			<< shallowCat->getBrain()->getIdea(0)
			<< "\n";

		msg("Shallow cats go to sleep.");
		delete shallowCat;
		//delete shallowCatTest; //! <-- This pointer is linked with the previous one (shallow cat).

		msg("End of Scope");
	}
	return (0);
}
