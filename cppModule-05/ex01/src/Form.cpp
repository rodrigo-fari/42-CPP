/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:20:09 by rde-fari          #+#    #+#             */
/*   Updated: 2026/01/10 11:55:40 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _signed(false), _gradeToSign(10), _gradeToExec(50)
{
	COUT << "📝: Default constructor called." << ENDL;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	:_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	COUT << "📝: Param constructor called." << ENDL;
	if (gradeToExec < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& original)
	:_name(original._name), _signed(original._signed),
	_gradeToSign(original._gradeToSign), _gradeToExec(original._gradeToExec)
{
	COUT << "📝: Copy operator called." << ENDL;
}

Form& Form::operator=(const Form& rhs)
{
	COUT << "📝: Copy assignement operator called." << ENDL;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
}

Form::~Form()
{
	COUT << "📝: Destructor called." << ENDL;
}

std::string	Form::getName() const
{
	return(this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& bcrat)
{
	if (bcrat.getGrade() > this->getGradeToSign())
	{
		COUT << bcrat.getName() << " couldn’t sign " << this->getName()
			<< " because grade is too low" << ENDL;
		throw GradeTooLowException();
	}
	COUT << bcrat.getName() << " signed " << this->getName() << ENDL;
	this->_signed = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high!");
}

std::ostream &operator<<(std::ostream &out, const Form& form)
{
	out << "====== Form's info ======"<< ENDL
		<< "Name: " << form.getName() << ENDL
		<< "Is signed: " << form.getSigned() << ENDL
		<< "Minimum grade to sign: " << form.getGradeToSign() << ENDL
		<< "Minimum grade to execute: " << form.getGradeToExec() << ENDL
		<< "=========================" << ENDL;
	return (out);
}