/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:22:40 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/20 19:43:55 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "🧠: Brain default constructor called." << std::endl;
}

Brain::Brain( const Brain& other) {
	std::cout << "🧠: Brain copy constructor called." << std::endl;
	this->_ideas[100] = other._ideas[100];
}

Brain::~Brain() {
	std::cout << "🧠: Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		};
	}
	return (*this);
}
