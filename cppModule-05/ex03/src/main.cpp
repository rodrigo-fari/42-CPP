/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/26 21:13:49 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	{
		std::cout << YELLOW << "\n=== Testing Bureaucrat & Forms ===" << RESET << std::endl << std::endl;
	}
	{
		try {
			std::cout << BLUE << "Test 1: PresidentialPardonForm" << RESET << std::endl;
			Intern intern;
			AForm *f1 = intern.makeForm("presidential pardon", "target1");
			std::cout << std::endl << *f1 << std::endl;
			Bureaucrat b1("b1", 4);
			std::cout << b1 << std::endl;
			b1.signForm(*f1);
			delete f1;
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << BLUE << "Test 2: ShrubberyCreationForm" << RESET << std::endl;
			Intern intern;
			AForm *f2 = intern.makeForm("shrubbery creation", "target2");
			std::cout << std::endl << *f2 << std::endl;
			Bureaucrat b2("b2", 132);
			std::cout << b2 << std::endl;
			b2.signForm(*f2);
			delete f2;
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	{
		try {
			std::cout << BLUE << "Test 3: RobotomyRequestForm" << RESET << std::endl;
			Intern intern;
			AForm *f3 = intern.makeForm("robotomy request", "target3");
			std::cout << std::endl << *f3 << std::endl;
			Bureaucrat b3("b3", 120);
			std::cout << b3 << std::endl;
			b3.signForm(*f3);
			delete f3;
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}

	std::cout << YELLOW << "=== All tests completed ===" << RESET << std::endl;
	return (0);
}