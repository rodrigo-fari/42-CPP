/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/01/10 10:27:10 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	COUT << YELLOW << "\n=== Testing Bureaucrat Class ===" << RESET << ENDL << ENDL;

	// Test 1: Valid bureaucrat
	COUT << BLUE << "Test 1: Creating valid bureaucrat" << RESET << ENDL;
	try
	{
		Bureaucrat b1("Alice", 75);
		COUT << b1 << ENDL;
	}
	catch (std::exception &e)
	{
		COUT << RED << e.what() << RESET << ENDL;
	}
	COUT << ENDL;

	// Test 2: Grade too high (< 1)
	COUT << BLUE << "Test 2: Creating bureaucrat with grade too high (0)" << RESET << ENDL;
	try
	{
		Bureaucrat b2("Bob", 0);
		COUT << b2 << ENDL;
	}
	catch (std::exception &e)
	{
		COUT << RED << e.what() << RESET << ENDL;
	}
	COUT << ENDL;

	// Test 3: Grade too low (> 150)
	COUT << BLUE << "Test 3: Creating bureaucrat with grade too low (151)" << RESET << ENDL;
	try
	{
		Bureaucrat b3("Charlie", 151);
		COUT << b3 << ENDL;
	}
	catch (std::exception &e)
	{
		COUT << RED << e.what() << RESET << ENDL;
	}
	COUT << ENDL;

	// Test 4: Increase grade
	COUT << BLUE << "Test 4: Increasing grade" << RESET << ENDL;
	try
	{
		Bureaucrat b4("David", 2);
		COUT << b4 << ENDL;
		b4.increaseGrade();
		COUT << b4 << ENDL;
		b4.increaseGrade(); // Should throw exception
		COUT << b4 << ENDL;
	}
	catch (std::exception &e)
	{
		COUT << RED << e.what() << RESET << ENDL;
	}
	COUT << ENDL;

	// Test 5: Decrease grade
	COUT << BLUE << "Test 5: Decreasing grade" << RESET << ENDL;
	try
	{
		Bureaucrat b5("Eve", 149);
		COUT << b5 << ENDL;
		b5.decreaseGrade();
		COUT << b5 << ENDL;
		b5.decreaseGrade(); // Should throw exception
		COUT << b5 << ENDL;
	}
	catch (std::exception &e)
	{
		COUT << RED << e.what() << RESET << ENDL;
	}
	COUT << ENDL;

	COUT << YELLOW << "=== All tests completed ===" << RESET << ENDL;
	return (0);
}