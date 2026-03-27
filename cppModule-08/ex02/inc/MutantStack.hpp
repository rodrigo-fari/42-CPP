/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:02:09 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/27 16:45:35 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>
# include <exception>

//Container = typename from std::deque that exists inside std::stack (From stack that has deque in it)(debug)
//c.smt is the protected member from std::stack. (debug)
template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
	public:
		//ocf
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();
		
		//Normal Iterators
		typename Container::iterator iterator;
		iterator begin();
		iterator end();
		
		typename Container::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
		
		//Reverse Iterators
		typename Container::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		typename Container::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

# include "MutantStack.tpp"

#endif