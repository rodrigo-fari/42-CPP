/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/01/10 22:12:42 by rde-fari         ###   ########.fr       */
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
		Form f1("Form1", 30, 30);
		COUT << f1 << ENDL;
		b1.signForm(f1);
		COUT << f1 << ENDL;
	}
	{
		COUT << ENDL;
		COUT << BLUE << "Test 2: Creating invalid bureaucrat and form situation." << RESET << ENDL;
		Bureaucrat b1("Alice", 31);
		Form f1("Form1", 30, 30);
		COUT << f1 << ENDL;
		b1.signForm(f1);
		COUT << f1 << ENDL;
	}
}