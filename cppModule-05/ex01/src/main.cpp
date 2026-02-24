/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 22:18:46 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		COUT << YELLOW << "\n=== Testing Bureaucrat & Forms ===" << RESET << ENDL << ENDL;

		// Test 1: Valid bureaucrat
		COUT << BLUE << "Test 1: Creating valid bureaucrat and form situation." << RESET << ENDL;
		Bureaucrat b1("Alice", 30);
		COUT << ENDL << b1 << ENDL;
		Form f1("Form1", 30, 30);
		COUT << f1 << ENDL;
		b1.signForm(f1);
		COUT << f1 << ENDL;
		b1.signForm(f1);
		COUT << "\n";
	}
	{
		COUT << ENDL;
		COUT << BLUE << "Test 2: Creating invalid bureaucrat and form situation." << RESET << ENDL;
		Bureaucrat b1("Alice", 31);
		COUT << ENDL << b1 << ENDL;
		Form f1("Form1", 30, 30);
		COUT << f1 << ENDL;
		b1.signForm(f1);
		COUT << f1 << ENDL;
	}
}