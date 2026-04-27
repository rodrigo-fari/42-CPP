/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:53:30 by rde-fari          #+#    #+#             */§
/*   Updated: 2026/04/20 16:31:30 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//----------------------------------------| OCF IMPLEMENTATION |

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _dataCsv(other._dataCsv) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->_dataCsv = other._dataCsv;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

//----------------------------------------| MEMBER FUNCTIONS IMPLEMENTATION |

void BitcoinExchange::importDatabase(const std::string dbFile) {
	std::ifstream openedFile(dbFile.c_str());
	if (!openedFile.is_open())
		throw UnableToLoadDataBaseFileException();

	std::string splitedLine;
	std::getline(openedFile, splitedLine);
	
	while(std::getline(openedFile,splitedLine))
	{
		size_t commaFind = splitedLine.find(',');
		if (commaFind != std::string::npos)
		{
			std::string date = splitedLine.substr(commaFind + 1).c_str();
			double rate = std::strtod(splitedLine.substr(commaFind + 1).c_str(), NULL);
			_dataCsv[date] = rate;
		}
	}
	openedFile.close();
}

bool BitcoinExchange::parseDate(const std::string& date) {

	
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	int day, month, year;
	char dashOne, dashTwo;
	
	std::istringstream iss(date);
	
	iss >> year >> dashOne >> month >> dashTwo >> day;
	
	if (iss.fail() || !iss.eof())
		return (false);
	if (year < 2009)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeapYear && day > 29)
			return false;
		if (!isLeapYear && day > 28)
			return false;
	}
	return (true);
}

bool BitcoinExchange::parseValue(const std::string& valueStr, double& value) {

	std::istringstream iss(valueStr);

	iss >> value;

	if (iss.fail() || !iss.eof())
		return (false);

	return (true);
}

void	BitcoinExchange::parseInputFile(const std::string& inputFile) {
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw UnableToOpenInputFileException();
	std::string line;
	std::getline(file, line);

	while(std::getline(file,line)) {
		
		size_t pipeFind = line.find(" | ");

		if (pipeFind == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ; 
		}
		
		std::string date = line.substr(0, pipeFind);
		std::string valueStr = line.substr(pipeFind + 3);
		double value;

		if (!parseDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		} if (!parseValue(valueStr, value)) {
			std::cerr << "Error: Not a valid number." << std::endl;
			continue ;
		} if (value < 0) {
			std::cerr << "Error: Not a positive number." << std::endl;
			continue ;
		} if (value > 1000) {
			std::cerr << "Error: too large number." << std::endl;
			continue ;
		}

		std::map<std::string, double>::iterator it = _dataCsv.lower_bound(date);

		if (it != _dataCsv.end() && it->first == date)
			std::cout << date << " => " << value << " = " << std::setprecision(6) << (value * it->second) << std::endl;
		else if (it == _dataCsv.begin())
			std::cerr << "Error: no older date found in database => " << date << std::endl;
		else {
			--it;
			std::cout << date << " => " << value << " = " <<  std::setprecision(6) << (value * it->second) << std::endl;
		}
	}
	file.close();
}

//----------------------------------------| EXCEPTIONS IMPLEMENTATION |

const char* BitcoinExchange::InvalidInputFileException::what() const throw() {
	return ("Error: Input file not valid or missing.");
}

const char* BitcoinExchange::UnableToOpenInputFileException::what() const throw() {
	return ("Error: Unable to open input file.");
}

const char* BitcoinExchange::UnableToLoadDataBaseFileException::what() const throw() {
	return ("Error: Unable to load database file.");
}

const char* BitcoinExchange::UnableToOpenDataBaseFileException::what() const throw() {
	return ("Error: Unable to open database file.");
}

const char* BitcoinExchange::InvalidOperationException::what() const throw() {
	return ("Error: Invalid operation!");
}

