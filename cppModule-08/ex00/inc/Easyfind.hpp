/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:20:02 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/24 20:22:40 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <cstdlib>
# include <string>
# include <exception>

# include <vector>
# include <map>
# include <set>
# include <unordered_map>
# include <list>
# include <deque>
# include <stack>
# include <queue>

class EmptyContainerException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class NumberDoesNotExistsException : public std::exception {
	public:
		virtual const char* what() const throw();
};

template<typename T> int easyfind(T* container, int nbr) {
	if (container->empty())
		throw EmptyContainerException();
	for (size_t i = 0; i < container->size(); i++) {
		if (container->at(i) == nbr)
			return(i);
	}
	return (throw NumberDoesNotExistsException(), 1);
}

#endif