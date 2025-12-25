/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 01:43:11 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/25 01:59:50 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cctype>
# include <exception>
# include "Colors.hpp"

# define OUT std::cout
# define NL std::endl
# define STRING std::string
# define NA ""

class Bureaucrat {
	private:
		std::string const _name;
		int _grade;

	public:
		//OCF
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& original);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		//Getters
		const std::string getName() const;
		int getGrade() const;

		//Setters
		void setGrade(int grade);

		//Controllers
		void increaseGrade();
		void decreaseGrade();
		
		class GradeTooHighException : public std::exception {
			public:
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw();
		};

};

//Operator Overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif