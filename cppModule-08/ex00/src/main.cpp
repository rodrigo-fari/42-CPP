/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:20:31 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 20:19:23 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

const char* EmptyContainerException::what() const throw()
{
	return ("Error: Container is empty!");
}

const char* NumberDoesNotExistsException::what() const throw()
{
	return ("Error: Number does not exists in container!");
}

int main(void)
{
	{
		std::vector<int> vet1;
		for(size_t i = 0; i < 10; i++) {
			vet1.push_back(i + 1);
		}
		try {
			std::cout << easyfind(&vet1, 6) << std::endl;		
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::vector<int> vet1;
		try {
			std::cout << easyfind(&vet1, 6) << std::endl;		
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
		std::vector<int> vet1;
		for(size_t i = 0; i < 4; i++) {
			vet1.push_back(i + 1);
		}
		try {
			std::cout << easyfind(&vet1, 6) << std::endl;		
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	return (0);
}
