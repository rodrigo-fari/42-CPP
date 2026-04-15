/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:53:30 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/15 11:48:25 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	
}

BitcoinExchange::~BitcoinExchange() {
	
}

const std::string& BitcoinExchange::getData() const {
	
}

void BitcoinExchange::setupData(std::string newData) {
	
}

const char* BitcoinExchange::InvalidInputFileException::what() const throw() {
	return ("Error: Input file not valid or missing.");
}

const char* BitcoinExchange::UnableToOpenFileException::what() const throw() {
	return ("Error: Unable to open file.");
}

const char* BitcoinExchange::InvalidOperationException::what() const throw() {
	return ("Error: Invalid operation!");
}

std::ostream& operator<<(std::ostream& out, const BitcoinExchange& other) {
	
}