/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/25 15:50:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	OUT << YELLOW << "\n=== Testing Bureaucrat Class ===" << RESET << NL << NL;

	// Test 1: Valid bureaucrat
	OUT << BLUE << "Test 1: Creating valid bureaucrat" << RESET << NL;
	try
	{
		Bureaucrat b1("Alice", 75);
		OUT << b1 << NL;
	}
	catch (std::exception& e)
	{
		OUT << RED << e.what() << RESET << NL;
	}
	OUT << NL;

	// Test 2: Grade too high (< 1)
	OUT << BLUE << "Test 2: Creating bureaucrat with grade too high (0)" << RESET << NL;
	try
	{
		Bureaucrat b2("Bob", 0);
		OUT << b2 << NL;
	}
	catch (std::exception& e)
	{
		OUT << RED << e.what() << RESET << NL;
	}
	OUT << NL;

	// Test 3: Grade too low (> 150)
	OUT << BLUE << "Test 3: Creating bureaucrat with grade too low (151)" << RESET << NL;
	try
	{
		Bureaucrat b3("Charlie", 151);
		OUT << b3 << NL;
	}
	catch (std::exception& e)
	{
		OUT << RED << e.what() << RESET << NL;
	}
	OUT << NL;

	// Test 4: Increase grade
	OUT << BLUE << "Test 4: Increasing grade" << RESET << NL;
	try
	{
		Bureaucrat b4("David", 2);
		OUT << b4 << NL;
		b4.increaseGrade();
		OUT << b4 << NL;
		b4.increaseGrade(); // Should throw exception
		OUT << b4 << NL;
	}
	catch (std::exception& e)
	{
		OUT << RED << e.what() << RESET << NL;
	}
	OUT << NL;

	// Test 5: Decrease grade
	OUT << BLUE << "Test 5: Decreasing grade" << RESET << NL;
	try
	{
		Bureaucrat b5("Eve", 149);
		OUT << b5 << NL;
		b5.decreaseGrade();
		OUT << b5 << NL;
		b5.decreaseGrade(); // Should throw exception
		OUT << b5 << NL;
	}
	catch (std::exception& e)
	{
		OUT << RED << e.what() << RESET << NL;
	}
	OUT << NL;

	OUT << YELLOW << "=== All tests completed ===" << RESET << NL;
	return (0);
}