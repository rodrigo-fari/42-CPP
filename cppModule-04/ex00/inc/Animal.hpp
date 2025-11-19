/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:47:20 by rde-fari          #+#    #+#             */
/*   Updated: 2025/11/10 21:36:21 by rde-fari         ###   ########.fr       */
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
		std::string	type;
	public:
		Animal();
		void	setType(std::string type);
		void	getType(std::string type);
};

#endif