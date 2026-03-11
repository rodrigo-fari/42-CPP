/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:45:50 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/11 13:57:01 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
/* 
FUNCTION parseChar(input, outputData)
    // CASE 1: Input is a single character (no quotes)
    IF input length == 1 THEN
        outputData.char = input[0]
        RETURN
    
    // CASE 2: Input is a char literal with quotes like 'a'
    IF input length == 3 AND input[0] == '\'' AND input[2] == '\'' THEN
        outputData.char = input[1]  // the middle character
        RETURN
    
    // CASE 3: Input is a numeric string (like "42")
    TRY to convert input to a number
        value = convert input to double
        
        IF conversion failed THEN
            outputData.char = IMPOSSIBLE
            RETURN
            
        IF value is nan, inf, or outside char range THEN
            outputData.char = IMPOSSIBLE
            RETURN
            
        // Convert number to char
        c = cast value to char
        
        IF c is printable THEN
            outputData.char = c
        ELSE
            outputData.char = NON_PRINTABLE
            
    CATCH conversion error
        outputData.char = IMPOSSIBLE
*/
static void parseChar(std::string& inputData, OutputData* outpData)
{
	if (inputData.length() == 1)
	{
		outpData->chr = inputData[0];
		return ;
	}

	if (inputData.length() == 3 && inputData[0] == '\'' && inputData[2] == '\'')
	{
		outpData->chr = inputData[1];
		return ;
	}
	
	int value = std::strtod(inputData.c_str(), NULL);

	if (value < 32 || value > 126)
		outpData->chr = NON_PRINTABLE;
	else
		outpData->chr = static_cast<char>(value);
}

static void parseInt(int inputData, OutputData* outpData)
{
	
}

static void parseFloat(int inputData, OutputData* outpData)
{
	
}

static void parseDouble(int inputData, OutputData* outpData)
{
	
}

static void printData(OutputData* outpData)
{
	std::cout

}

void ScalarConverter::convert(std::string& baseString)
{
	OutputData outpData;

	

	parseChar(baseString, &outpData);
	parseInt(inputData, &outpData);
	parseFloat(inputData, &outpData);
	parseDouble(inputData, &outpData);

	printData(&outpData);
}
