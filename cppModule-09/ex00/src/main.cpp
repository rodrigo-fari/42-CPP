/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:15:38 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/15 11:45:39 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool setupInputData(char *file) {
	/* 
		Função setupInputData:
		- Verifica se o ficheiro é válido:
			- Ficheiro tem que ser ".txt";
				- Se nao return false;
			- Valores tem que ser um int ou float e positivos; (bool parse value)
				- Se nao return false;
			- Datas no formato yyyy-mm-dd, e válidas; (bool parseDate())
				- Se nao return false;
		- Passa tudo para o _data;
	*/
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	std::cout << "HelloWorld" << std::endl;
	return (0);
}

