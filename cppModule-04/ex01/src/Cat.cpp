/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:50:45 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/20 22:45:28 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "🐈: Cat default constructor called." << std::endl;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "🐈: Cat destructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal() {
	std::cout << "🐈: Cat copy operator called." << std::endl;
	this->_type = other._type;
	this->_brain = other._brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "🐈: Cat copy assignment operator called. " << std::endl;
	if (this != &other) {
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "🐈: Miau - (Kitty sounds)." << std::endl;
}

Brain* Cat::getBrain() const {
	return this->_brain;
}
