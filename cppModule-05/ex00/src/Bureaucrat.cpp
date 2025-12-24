/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:15 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/24 22:55:26 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(10) {
	OUT << "🎩: Default constructor called." << NL;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) {
	OUT << "🎩: Copy constructor called." << NL;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	OUT << "🎩: Copy assignment operator called." << NL;
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	OUT << "🎩: Destructor called" << NL;
}

const std::string Bureaucrat::getName() {
	return (this->_name);
}

void Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

void Bureaucrat::increaseGrate() {
	if (this->_grade > 1) {
		this->_grade = this->_grade--;
	} else {
		throw GradeTooHighException();
	}
}

void Bureaucrat::decreaseGrate() {
	if (this->_grade < 150) {
		this->_grade = this->_grade++;
	} else {
		throw GradeTooLowException();
	}
}

const char* GradeTooLowException::what() const throw() {
	return ("Error: Grade is too low!");
}

const char* GradeTooHighException::what() const throw() {
	return ("Error:Grade is too high!");
}

std::string errorMessage() {
	
}