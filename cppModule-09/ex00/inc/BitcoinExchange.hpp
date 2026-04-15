/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:15:26 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/15 11:46:40 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _data; 

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
	
		const std::string& BitcoinExchange::getData() const;
		
		void setupData(std::string newData);
		
		class InvalidOperationException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class UnableToOpenFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class InvalidInputFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& other);

#endif