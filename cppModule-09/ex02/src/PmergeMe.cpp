/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:37:05 by rde-fari          #+#    #+#             */
/*   Updated: 2026/04/27 15:30:04 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//*|-------------------------------| OCF |

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) : _vect(other._vect), _deck(other._deck) { }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->_vect = other._vect;
		this->_deck = other._deck;
	}
	return (*this);
}

PmergeMe::~PmergeMe() { }

//*|-------------------------------| PUBLIC METHODS |

//??-------------------------------------|Getters
size_t PmergeMe::getVectorSize() const {
	return _vect.size();
}

size_t PmergeMe::getDequeSize() const {
	return _deck.size();
}
//??-------------------------------------|


//??-------------------------------------|Setters
void PmergeMe::setVectorValues(const std::vector<int>& vect) {
	this->_vect = vect;
}

void PmergeMe::setDequeValues(const std::deque<int>& deq) {
	this->_deck = deq;
}
//??-------------------------------------|



//??-------------------------------------|Sorters
void PmergeMe::sortVector() {
	if (_vect.size() <= 1) return;
	fordJohnsonSortVector(_vect);
}

void PmergeMe::sortDeque() {
	if (_deck.size() <= 1) return;
	fordJohnsonSortDeque(_deck);
}
//??-------------------------------------|



//??-------------------------------------|Print info
void PmergeMe::printVector() const {
	for (size_t i = 0; i < _vect.size(); ++i) {
		std::cout << _vect[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() const {
	for (size_t i = 0; i < _deck.size(); ++i) {
		std::cout << _deck[i] << " ";
	}
	std::cout << std::endl;
}

//*|-------------------------------| JACOBSTHAL IMPLEMENTATION |


//??-------------------------------------| JS formula |
int PmergeMe::getJacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	
	int a = 0, b = 1;
	for (int i = 2; i <= n; i++) {
		int next = b + 2 * a;
		a = b;
		b = next;
	}
	return b;
}

//??-------------------------------------| Sequence generator based on numbers ammount |
std::vector<int> PmergeMe::generateJacobsthalUpTo(int maxValue) {
	std::vector<int> sequence;
	sequence.push_back(0);
	sequence.push_back(1);
	
	int i = 2;
	while (true) {
		int next = getJacobsthal(i);
		if (next > maxValue) break;
		sequence.push_back(next);
		i++;
	}
	return sequence;
}

//??-------------------------------------| Insert order generator |
std::vector<int> PmergeMe::getInsertionOrder(int pendentCount) {
	std::vector<int> order;
	std::vector<bool> used(pendentCount + 1, false);
	
	// Regra: primeiro elemento sempre 1
	order.push_back(1);
	used[1] = true;
	
	// Gerar sequência de Jacobsthal
	std::vector<int> jacob = generateJacobsthalUpTo(pendentCount);
	
	// Construir ordem baseada na sequência de Jacobsthal
	for (size_t i = 2; i < jacob.size(); i++) {
		int current = jacob[i];
		int previous = jacob[i - 1];
		
		for (int num = current; num > previous; num--) {
			if (num <= pendentCount && !used[num]) {
				order.push_back(num);
				used[num] = true;
			}
		}
	}
	
	// Adicionar elementos faltantes (caso ímpar)
	for (int i = 1; i <= pendentCount; i++) {
		if (!used[i]) {
			order.push_back(i);
		}
	}
	
	return order;
}

//*|-------------------------------| BINARY SEARCH IMPLEMENTATION |

int PmergeMe::binarySearchVector(const std::vector<int>& arr, int value) {
	int left = 0;
	int right = arr.size() - 1;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == value) {
			return mid;
		} else if (arr[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int value) {
	int left = 0;
	int right = arr.size() - 1;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == value) {
			return mid;
		} else if (arr[mid] < value) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

//*|-------------------------------| FORD-JOHNSON FOR VECTOR |

void PmergeMe::fordJohnsonSortVector(std::vector<int>& container) {
	if (container.size() <= 1) return;
	
	// Passo 1: Formar pares
	std::vector<Pair> pairs;
	int oddElement = -1;
	bool hasOdd = (container.size() % 2 != 0);
	
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		int a = container[i];
		int b = container[i + 1];
		if (a > b) std::swap(a, b);
		pairs.push_back(Pair(a, b));
	}
	
	if (hasOdd) {
		oddElement = container.back();
	}
	
	// Passo 2: Ordenar pares pelo maior elemento
	for (size_t i = 1; i < pairs.size(); i++) {
		Pair key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].larger > key.larger) {
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
	
	// Passo 3: Extrair main chain e pendents
	std::vector<int> mainChain;
	std::vector<int> pendents;
	
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].larger);
		pendents.push_back(pairs[i].smaller);
	}
	
	// Passo 4: Obter ordem de inserção de Jacobsthal
	std::vector<int> insertOrder = getInsertionOrder(pendents.size());
	
	// Passo 5: Inserir pendents na ordem correta
	for (size_t i = 0; i < insertOrder.size(); i++) {
		int idx = insertOrder[i] - 1; // converter para 0-based
		int value = pendents[idx];
		int pos = binarySearchVector(mainChain, value);
		mainChain.insert(mainChain.begin() + pos, value);
	}
	
	// Passo 6: Inserir elemento sobrante (se existir)
	if (hasOdd) {
		int pos = binarySearchVector(mainChain, oddElement);
		mainChain.insert(mainChain.begin() + pos, oddElement);
	}
	
	// Copiar de volta para o container
	container = mainChain;
}

//*|-------------------------------| FORD-JOHNSON FOR DEQUE |

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& container) {
	if (container.size() <= 1) return;
	
	// Passo 1: Formar pares
	std::deque<Pair> pairs;
	int oddElement = -1;
	bool hasOdd = (container.size() % 2 != 0);
	
	for (size_t i = 0; i + 1 < container.size(); i += 2) {
		int a = container[i];
		int b = container[i + 1];
		if (a > b) std::swap(a, b);
		pairs.push_back(Pair(a, b));
	}
	
	if (hasOdd) {
		oddElement = container.back();
	}
	
	// Passo 2: Ordenar pares pelo maior elemento
	for (size_t i = 1; i < pairs.size(); i++) {
		Pair key = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].larger > key.larger) {
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = key;
	}
	
	// Passo 3: Extrair main chain e pendents
	std::deque<int> mainChain;
	std::deque<int> pendents;
	
	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].larger);
		pendents.push_back(pairs[i].smaller);
	}
	
	// Passo 4: Obter ordem de inserção de Jacobsthal
	std::vector<int> insertOrder = getInsertionOrder(pendents.size());
	
	// Passo 5: Inserir pendents na ordem correta
	for (size_t i = 0; i < insertOrder.size(); i++) {
		int idx = insertOrder[i] - 1;
		int value = pendents[idx];
		int pos = binarySearchDeque(mainChain, value);
		
		// Inserção manual para C++98 (deque::insert existe)
		std::deque<int>::iterator it = mainChain.begin();
		for (int j = 0; j < pos; j++) it++;
		mainChain.insert(it, value);
	}
	
	// Passo 6: Inserir elemento sobrante
	if (hasOdd) {
		int pos = binarySearchDeque(mainChain, oddElement);
		std::deque<int>::iterator it = mainChain.begin();
		for (int j = 0; j < pos; j++) it++;
		mainChain.insert(it, oddElement);
	}
	
	container = mainChain;
}

//*|-------------------------------| AUX FUNCTIONS |

std::vector<int> stringToIntVector(const std::string &str) {
	std::vector<int> result;
	std::stringstream ss(str);
	std::string word;
	
	while (ss >> word) {
		for (size_t i = 0; i < word.size(); i++) {
			if (word[i] == '+' || word[i] == '-')
				throw PmergeMe::SignalsFoundException();
			if (!std::isdigit(word[i]))
				throw PmergeMe::NonNumericExpressionFoundException();
		}
		std::stringstream iss(word);
		long long nbr;
		iss >> nbr;
		
		if (nbr > INT_MAX || nbr < 0)
			throw PmergeMe::NumberOverBounderiesException();
		
		result.push_back(static_cast<int>(nbr));
	}
	if (!checkDuplicates(result))
		throw PmergeMe::DuplicateNumberFoundException();
	
	return result;
}

std::deque<int> stringToIntDeque(const std::string &str) {
	std::deque<int> result;
	std::stringstream ss(str);
	std::string word;
	
	while (ss >> word) {
		for (size_t i = 0; i < word.size(); i++) {
			if (word[i] == '+' || word[i] == '-')
				throw PmergeMe::SignalsFoundException();
			if (!std::isdigit(word[i]))
				throw PmergeMe::NonNumericExpressionFoundException();
		}
		std::stringstream iss(word);
		long long nbr;
		iss >> nbr;
		
		if (nbr > INT_MAX || nbr < 0)
			throw PmergeMe::NumberOverBounderiesException();
		
		result.push_back(static_cast<int>(nbr));
	}
	
	// Converter deque para vector para verificar duplicatas
	std::vector<int> temp(result.begin(), result.end());
	if (!checkDuplicates(temp))
		throw PmergeMe::DuplicateNumberFoundException();
	
	return result;
}

bool checkDuplicates(std::vector<int> vect) {
	if (vect.size() <= 1) return true;
	
	std::vector<int> vectCopy = vect;
	std::sort(vectCopy.begin(), vectCopy.end());
	
	for (size_t i = 0; i + 1 < vectCopy.size(); i++) {
		if (vectCopy[i] == vectCopy[i + 1])
			return false;
	}
	return true;
}

double getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec / 1000000.0;
}

//*|-------------------------------| EXCEPTIONS |

const char* PmergeMe::DuplicateNumberFoundException::what() const throw() {
	return ("Error: No duplicated numbers are allowed.");
}

const char* PmergeMe::NonNumericExpressionFoundException::what() const throw() {
	return ("Error: Only numbers are allowed.");
}

const char* PmergeMe::SignalsFoundException::what() const throw() {
	return ("Error: No mathematical symbols are allowed.");
}

const char* PmergeMe::NumberOverBounderiesException::what() const throw() {
	return ("Error: Only INT numbers are allowed (0 to INT_MAX).");
}