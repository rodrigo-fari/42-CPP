/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:15 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/25 02:20:25 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(10) {
	OUT << "🎩: Default constructor called." << NL;
}

//Param constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	OUT << "🎩: Param constructor called." << NL;
	setGrade(grade);
}

//Copy operator
Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) {
	OUT << "🎩: Copy operator called." << NL;
}

//Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	OUT << "🎩: Copy assignment operator called." << NL;
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

//Destructor
Bureaucrat::~Bureaucrat() {
	OUT << "🎩: Destructor called" << NL;
}

//Getters
const std::string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

//Setters
void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else {
		OUT << "Setting " << BLUE
		<< this->getName() << RESET
		<< " grade to " << YELLOW
		<< grade << RESET << NL;
		this->_grade = grade;
	}
}

//Controllers
void Bureaucrat::increaseGrade() {
	OUT << "Increasing " << BLUE << this->getName() << RESET << " grade." << NL;
	if (this->_grade > 1) {
		this->_grade--;
	} else {
		throw GradeTooHighException();
	}
}

void Bureaucrat::decreaseGrade() {
	OUT << "Decreasing " << BLUE << this->getName() << RESET << " grade." << NL;
	if (this->_grade < 150) {
		this->_grade++;
	} else {
		throw GradeTooLowException();
	}
}

//Own exceptions
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade is too low!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error:Grade is too high!");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << GREEN << bureaucrat.getName() << ", Bureaucrat grade " << bureaucrat.getGrade() << RESET;
	return (out);
}