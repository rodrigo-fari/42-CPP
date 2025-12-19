/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:22:40 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/19 15:53:18 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

Brain::Brain() {
	msg("Brain: Default constructor called.");
}

Brain::Brain( const Brain& other) {
	msg("Brain: Copy constructor called.");
	this->_ideas[100] = other._ideas[100];
}

Brain::~Brain() {
	msg("Brain: Destructor called.");
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		};
	}
	return (*this);
}

