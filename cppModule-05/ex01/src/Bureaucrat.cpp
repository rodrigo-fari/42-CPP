/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:15 by rde-fari          #+#    #+#             */
/*   Updated: 2026/02/24 22:14:41 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form

// Default constructor
Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(10)
{
	COUT << "🎩: Default constructor called." << ENDL;
}

// Param constructor
Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	COUT << "🎩: Param constructor called." << ENDL;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &original)
	: _name(original._name), _grade(original._grade)
{
	COUT << "🎩: Copy constructor called." << ENDL;
}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	COUT << "🎩: Copy assignment operator called." << ENDL;
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	COUT << "🎩: Destructor called" << ENDL;
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
	COUT << "Increasing " << getName() << " grade." << ENDL;
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade()
{
	COUT << "Decreasing " << getName() << " grade." << ENDL;
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		COUT << RED 
			<< getName()
			<< " couldn't sign "
			<< form.getName()
			<< " because "
			<< e.what()
			<< RESET
			<< ENDL;
	}
}

// Exception implementations

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high!");
}


// Operator overload

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ENDL;
	return (out);
}