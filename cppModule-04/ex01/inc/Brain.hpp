/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:22:27 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/13 20:38:33 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);

		const std::string getIdea();
		void setIdea(std::string idea);
};

#endif