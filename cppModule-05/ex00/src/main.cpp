/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 03:10:32 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/25 02:17:41 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// static void msg(STRING msg) {
// 	OUT << "<==|===========> " << msg << NL;
// }

static void testCreation() {
	OUT << YELLOW << "=== TEST CREATION ===" << NL << RESET;
	try
	{
		Bureaucrat b1;
		OUT << b1 << NL;
		Bureaucrat b2("Bureaucrat1", 1);
		OUT << b2 << NL;
		Bureaucrat b3("Bureaucrat1", 150);
		OUT << b3 << NL;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}

static void testError1() {
	OUT << NL <<YELLOW << "=== ERROR1 ===" << NL << RESET;
	try
	{
		Bureaucrat b1("B1", 0);
		OUT << b1 << NL;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}

static void testError2() {
	OUT << NL <<YELLOW << "=== ERROR2 ===" << NL << RESET;
	try
	{
		Bureaucrat b1("B1", 151);
		OUT << b1 << NL;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}

static void testSetGradeError1() {
	OUT << NL <<YELLOW << "=== setGradeError1 ===" << NL << RESET;
	try
	{
		Bureaucrat b1;
		b1.setGrade(0);
		OUT << b1 << NL;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}

static void testSetGradeError2() {
	OUT << NL <<YELLOW << "=== setGradeError2 ===" << NL << RESET;
	try
	{
		Bureaucrat b1;
		b1.setGrade(151);
		OUT << b1 << NL;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}

static void testIncDec() {
	OUT << NL <<YELLOW << "=== Increase & Decrease ===" << NL << RESET;
	try
	{
		Bureaucrat b1("LABUBU", 10);
		OUT << b1 << NL;
		b1.setGrade(1);
		OUT << b1 << NL;
		b1.decreaseGrade();
		OUT << b1 << NL;
		b1.increaseGrade();
		OUT << b1 << NL;
		b1.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
}



int main()
{
	testCreation();
	testError1();
	testError2();
	testSetGradeError1();
	testSetGradeError2();
	testIncDec();
	return (0);
}