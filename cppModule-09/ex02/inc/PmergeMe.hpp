#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <ctime>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _vect;
    std::deque<int> _deck;
    
    // Estrutura para armazenar pares
    struct Pair {
        int smaller;
        int larger;
        
        Pair(int s, int l) : smaller(s), larger(l) {}
    };
    
    // Métodos privados
    std::vector<int> generateJacobsthalUpTo(int maxValue);
    int getJacobsthal(int n);
    std::vector<int> getInsertionOrder(int pendentCount);
    
    // Merge sort para vector
    void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    void mergeSortVector(std::vector<int>& arr, int left, int right);
    
    // Merge sort para deque
    void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
    void mergeSortDeque(std::deque<int>& arr, int left, int right);
    
    // Ford-Johnson para vector
    void fordJohnsonSortVector(std::vector<int>& container);
    
    // Ford-Johnson para deque
    void fordJohnsonSortDeque(std::deque<int>& container);
    
    // Binary search para encontrar posição de inserção
    int binarySearchVector(const std::vector<int>& arr, int value);
    int binarySearchDeque(const std::deque<int>& arr, int value);
    
public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    // Métodos públicos
    void setVectorValues(const std::vector<int>& vect);
    void setDequeValues(const std::deque<int>& deq);
    
    void sortVector();
    void sortDeque();
    
    void printVector() const;
    void printDeque() const;
    
    size_t getVectorSize() const;
    size_t getDequeSize() const;
    
    // Exceções
    class DuplicateNumberFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NonNumericExpressionFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class SignalsFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NumberOverBounderiesException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Funções auxiliares (fora da classe)
std::vector<int> stringToIntVector(const std::string &str);
std::deque<int> stringToIntDeque(const std::string &str);
bool checkDuplicates(std::vector<int> vect);
bool checkDuplicatesDeque(std::deque<int> deq);
double getCurrentTime();

#endif