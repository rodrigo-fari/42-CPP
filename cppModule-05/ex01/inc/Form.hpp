/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:31:52 by rde-fari          #+#    #+#             */
/*   Updated: 2026/01/08 15:42:59 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		const int			_minToSign;
		const int			_minToExec;

	public:
		// Orthodox Canonical Form
		Form();
		Form(std::string name, int grade);
		Form(const Form& original);
		Form& operator=(const Form& rhs);
		~Form();

		// Getters
		const std::string	getName() const;
		bool				getSigned() const;
		const int			getMinToSign() const;
		const int			getMinToExec() const;

		// Member function
		void	beSigned(const Bureaucrat& bcrat);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Operator overload
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif