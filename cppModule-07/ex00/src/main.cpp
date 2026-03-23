/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:07:58 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/23 13:34:34 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		std::cout << "==============================| int |" << std::endl;
		int val1 = 10;
		int val2 = 42;
		std::cout << "==| Values |==\n" << std::endl;	
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| Swap Values |==\n" << std::endl;	
		swap(val1, val2);
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| MIN |==\n" << std::endl;	
		myMin(val1, val2);
		std::cout << "Min val = " << myMin(val1, val2) << "\n" <<std::endl;

		std::cout << "==| MAX |==\n" << std::endl;	
		myMax(val1, val2);
		std::cout << "Max val = " << myMax(val1, val2) << "\n" <<std::endl;
	}
	{
		std::cout << "==============================| std::string |" << std::endl;
		std::string val1 = "42";
		std::string val2 = "Porto";
		std::cout << "==| Values |==\n" << std::endl;	
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| Swap Values |==\n" << std::endl;	
		swap(val1, val2);
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| MIN |==\n" << std::endl;	
		myMin(val1, val2);
		std::cout << "Min val = " << myMin(val1, val2) << "\n" <<std::endl;

		std::cout << "==| MAX |==\n" << std::endl;	
		myMax(val1, val2);
		std::cout << "Max val = " << myMax(val1, val2) << "\n" <<std::endl;
	}
	{
		std::cout << "==============================| float |" << std::endl;
		float val1 = 10.5f;
		float val2 = 5.10f;
		std::cout << "==| Values |==\n" << std::endl;	
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| Swap Values |==\n" << std::endl;	
		swap(val1, val2);
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| MIN |==\n" << std::endl;	
		myMin(val1, val2);
		std::cout << "Min val = " << myMin(val1, val2) << "\n" <<std::endl;

		std::cout << "==| MAX |==\n" << std::endl;	
		myMax(val1, val2);
		std::cout << "Max val = " << myMax(val1, val2) << "\n" <<std::endl;
	}
	{
		std::cout << "==============================| char |" << std::endl;
		char val1 = 'a';
		char val2 = 'b';
		std::cout << "==| Values |==\n" << std::endl;	
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| Swap Values |==\n" << std::endl;	
		swap(val1, val2);
		std::cout << "Val1 = " << val1 << std::endl;
		std::cout << "Val2 = " << val2 << "\n" <<std::endl;

		std::cout << "==| MIN |==\n" << std::endl;	
		myMin(val1, val2);
		std::cout << "Min val = " << myMin(val1, val2) << "\n" <<std::endl;

		std::cout << "==| MAX |==\n" << std::endl;	
		myMax(val1, val2);
		std::cout << "Max val = " << myMax(val1, val2) << "\n" <<std::endl;
	}
	return (0);
}