/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:32:34 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/20 20:47:10 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << std::endl << "=============================================================| SCOPE 1 (Animals)" << std::endl;
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



	// std::cout << "=============================================================| SCOPE 2 (Wrong Animals)" << std::endl;
	// {
	// 	msg("Wrong Animal Creation");
	// 	const WrongAnimal* a = new WrongAnimal();
	// 	const WrongAnimal* b = new WrongCat();

	// 	msg("Wrong Animal Sounds");
	// 	a->makeSound();
	// 	b->makeSound();

	// 	msg("Wrong Animal Type");
	// 	std::cout << a->getType() << " " << std::endl;
	// 	std::cout << b->getType() << " " << std::endl;

	// 	msg("Wrong Animals go to sleep");
	// 	delete(a);
	// 	delete(b);

	// 	msg("End of Scope");
	// }



	// std::cout << "=============================================================| SCOPE 3 (Deep and Shallow)" << std::endl;
	// {
	// 	msg("Creating deepCat & shallowCat");
	// 	Cat* deepCat = new Cat;
	// 	Cat* shallowCat = new Cat;
		
	// 	msg("Setting deepCat & shallowCat Ideas (only 20 for testing.)");
	// 	for (int i = 0; i < 20; i++) {
	// 		if (i < 10) {
	// 			deepCat->setIdea(i, "I want fish.");
	// 		} else {
	// 			deepCat->setIdea(i, "I want MUCH MORE fish!");
	// 		}
	// 	}
	// 	for (int i = 0; i < 20; i++) {
	// 		if (i < 10) {
	// 			shallowCat->setIdea(i, "I want fish.");
	// 		} else {
	// 			shallowCat->setIdea(i, "I want MUCH MORE fish!");
	// 		}
	// 	}

	// 	msg("Verifying deepCat & shallowCat Ideas");
	// 	for (int i = 0; i < 20; i++) {
	// 		std::cout << "[Idea: " << i << " ]"
	// 		<< std::endl
	// 		<< "[deepCat] = " << deepCat->getIdea(i)
	// 		<< std::endl
	// 		<< "[shallowCat] = " << shallowCat->getIdea(i)
	// 		<< std::endl;
	// 	}

	// 	msg("Creating deepCatTest & shallowCatTest");
	// 	Cat* deepCatTest = deepCat;
	// 	Cat* shallowCatTest = new Cat(*shallowCat);

	// 	msg("Setting deepCatTest & shallowCatTest Ideas (only 20 for testing.)");
	// 	for (int i = 0; i < 20; i++) {
	// 		if (i < 10) {
	// 			deepCatTest->setIdea(i, "DEBUG deepCatTest IDEA 1");
	// 		} else {
	// 			deepCatTest->setIdea(i, "DEBUG deepCatTest IDEA 2");
	// 		}
	// 	}
	// 	for (int i = 0; i < 20; i++) {
	// 		if (i < 10) {
	// 			shallowCatTest->setIdea(i, "DEBUG shallowCatTest IDEA 1");
	// 		} else {
	// 			shallowCatTest->setIdea(i, "DEBUG shallowCatTest IDEA 2");
	// 		}
	// 	}

	// 	msg("Verifying deepCatTest & shallowCatTest Ideas");
	// 	for (int i = 0; i < 20; i++) {
	// 		std::cout << "[Idea: " << i << " ]"
	// 		<< std::endl
	// 		<< "[deepCat] = " << deepCatTest->getIdea(i)
	// 		<< std::endl
	// 		<< "[shallowCat] = " << shallowCatTest->getIdea(i)
	// 		<< std::endl;
	// 	}

	// 	msg("Verifying originals once again");
	// 	for (int i = 0; i < 20; i++) {
	// 		std::cout << "[Idea: " << i << " ]"
	// 		<< std::endl
	// 		<< "[deepCat] = " << deepCat->getIdea(i)
	// 		<< std::endl
	// 		<< "[shallowCat] = " << shallowCat->getIdea(i)
	// 		<< std::endl;
	// 	}

	// 	msg("Animals go to sleep");
	// 	delete deepCat;
	// 	delete deepCatTest;
	// 	delete shallowCat;
	// 	delete shallowCatTest;

	// 	msg("End of Scope");
	// }



// 	std::cout << "=============================================================| SCOPE 4 (Leeeeeeeeeeeeeeeaks.)" << std::endl;
// 	{

// 		const Animal *listAnimals[100];

// 		msg("Creation of Cats and Dogs.");
// 		for (int i = 0; i < 100; i++){
// 			std::cout << "[ " << i + 1 << " ] " << std::endl;
// 			if (i < 50) {
// 				listAnimals[i] = new Dog;
// 			} else {
// 				listAnimals[i] = new Cat;
// 			}
// 		}

// 		msg("Cats and Dogs go to sleep.");
// 		for (int i = 0; i < 100; i++){
// 			std::cout << "[ " << i + 1 << " ] " << std::endl;
// 			delete listAnimals[i];
// 			std::cout << std::endl;
// 		}
// 	}
	return (0);
}
