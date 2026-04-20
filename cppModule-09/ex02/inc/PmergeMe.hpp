/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:36:38 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/20 19:18:43 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <stack>
# include <string>
# include <vector>
# include <cstdlib>
# include <sstream>
# include <iostream>
# include <exception>

class PmergeMe {
	private:
		std::vector<int> _vect;
		std::deque<int> _deck;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
	
		class SomeException : public std::exception {
			public:
				const char* what() const throw();	
		};
};

#endif