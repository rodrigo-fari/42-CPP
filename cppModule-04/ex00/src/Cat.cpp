/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:50:45 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/30 12:56:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: Default destructor called." << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat: Copy operator called." << std::endl;
	this->_type = other._type;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Copy assignment operator called. " << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Cat::makeSound()
{
	std::cout << "INHAAAAAAAAAAWUAUUUU.(Angry cat sounds ofc.)" << std::endl;
}