/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:50:47 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/30 12:58:26 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: Default destructor called." << std::endl;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog: Copy operator called." << std::endl;
	this->_type = other._type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog: Copy assignment operator called. " << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return (*this);
}

void	Dog::makeSound() {
	std::cout << "AU AU e fds.(Projeto é meu o dog vai fazer a porra do barulho que eu quiser e fds.)" << std::endl;
}