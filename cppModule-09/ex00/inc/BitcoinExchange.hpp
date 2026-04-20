/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:15:26 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/20 16:02:28 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <cstdlib>
# include <sstream>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <exception>

class BitcoinExchange {
	private:
		std::map<std::string, double> _dataCsv;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void importDatabase(const std::string dbFile);
		bool parseDate(const std::string& date);
		bool parseValue(const std::string& valueStr, double& value);
		void parseInputFile(const std::string& inputFile);

		const std::map<std::string, double> getCsv() const {
			return (this->_dataCsv);
		}
		
		class InvalidOperationException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class UnableToOpenInputFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class UnableToLoadDataBaseFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};

		class UnableToOpenDataBaseFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};
		
		class InvalidInputFileException : public std::exception {
			public:
				virtual const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& obj);

#endif