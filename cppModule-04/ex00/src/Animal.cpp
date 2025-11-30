/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:58:44 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/30 12:56:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Defualt constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor called." << std::endl;
	this->_type = other._type;
}

Animal::~Animal()
{
	std::cout << "Default destructor called." << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copy assignment constructor called." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void Animal::makeSound()
{
	std::cout << "*Default animal sound.*" << std::endl;
}