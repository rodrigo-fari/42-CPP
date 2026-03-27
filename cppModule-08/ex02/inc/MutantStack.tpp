/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:02:29 by rde-fari          #+#    #+#             */
/*   Updated: 2026/03/27 16:46:03 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//Begin ocf

//Def constructor
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() { }

//Copy constructor
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other) { }

//Copy assignement operator
template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other) {
	if (this != &other) {
		std::stack<T, Container>::operator=(other);
	}
	return (*this);
} 

//Def destructor
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() { }

//End ocf

//Normal iterators begin
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return (this->c.begin());
}