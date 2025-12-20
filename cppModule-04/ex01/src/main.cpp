/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:32:34 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/20 19:41:20 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << std::endl << "=============================================================| SCOPE 1" << std::endl;
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
		std::cout << "=============================================================| SCOPE 2" << std::endl;
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
		std::cout << "=============================================================| SCOPE 3" << std::endl;
	{

		const Animal *listAnimals[100];

		msg("Creation of Cats and Dogs.");
		for (int i = 0; i < 100; i++){
			std::cout << "[ " << i + 1 << " ] " << std::endl;
			if (i < 50) {
				listAnimals[i] = new Dog;
			} else {
				listAnimals[i] = new Cat;
			}
		}

		msg("Cats and Dogs go to sleep.");
		for (int i = 0; i < 100; i++){
			std::cout << "[ " << i + 1 << " ] " << std::endl;
			delete listAnimals[i];
			std::cout << std::endl;
		}
	}
	return (0);
}
