/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:37:37 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/27 15:24:17 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: Please provide numbers to sort" << std::endl;
		return (1);
	}
	
	try {
		// Build string w/ all the args.
		std::string input;
		for (int i = 1; i < argc; i++) {
			input += argv[i];
			if (i + 1 < argc) input += " ";
		}
		
		// Convert to stl conteiners.
		std::vector<int> vec = stringToIntVector(input);
		std::deque<int> deq = stringToIntDeque(input);
		
		// Print original array.
		std::cout << "Before: ";
		for (size_t i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
		
		// Ordenar com vector
		PmergeMe sorter;
		sorter.setVectorValues(vec);
		sorter.setDequeValues(deq);
		
		double startVec = getCurrentTime();
		sorter.sortVector();
		double endVec = getCurrentTime();
		double timeVec = (endVec - startVec) * 1000000; // Micro seconds.
		
		double startDeq = getCurrentTime();
		sorter.sortDeque();
		double endDeq = getCurrentTime();
		double timeDeq = (endDeq - startDeq) * 1000000; // Micro seconds.
		
		// Print result.
		std::cout << "After: ";
		sorter.printVector();
		
		// Show performance difference between algrithms.
		std::cout << "Time to process a range of " << sorter.getVectorSize()
					<< " elements with std::vector: " << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << sorter.getDequeSize()
					<< " elements with std::deque: " << timeDeq << " us" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}