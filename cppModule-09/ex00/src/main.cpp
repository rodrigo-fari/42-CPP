/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:15:38 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/20 16:03:36 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	try {
	
		btc.importDatabase("data.csv"); //Load database to struct
		btc.parseInputFile(av[1]);
	
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}

