/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:47:20 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/30 12:53:04 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <cctype>
# include <iostream>
# include <sstream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();
		virtual void makeSound();
		Animal&	operator=( const Animal& other );

		std::string getType() const;
};

#endif