/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:15 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/25 16:01:04 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Orthodox Canonical Form

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(10)
{
	OUT << "🎩: Default constructor called." << NL;
}

// Param constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	OUT << "🎩: Param constructor called." << NL;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade)
{
	OUT << "🎩: Copy constructor called." << NL;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	OUT << "🎩: Copy assignment operator called." << NL;
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	OUT << "🎩: Destructor called" << NL;
}

// Getters

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}


// Member functions

void Bureaucrat::increaseGrade()
{
	OUT << "Increasing " << BLUE << getName() << RESET << " grade." << NL;
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	OUT << "Decreasing " << BLUE << getName() << RESET << " grade." << NL;
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

// Exception implementations

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high!");
}

// Operator overload

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << GREEN << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << RESET;
	return (out);
}