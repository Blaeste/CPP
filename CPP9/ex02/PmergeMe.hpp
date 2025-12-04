/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:54:50 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/04 10:16:36 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =============================================================================
// Includes

#pragma once
#include <string>
#include <vector>
#include <deque>
#include <stdexcept>

// =============================================================================
// Typedef

typedef std::vector<int> IntVector;
typedef std::deque<int> IntDeque;
typedef std::vector<size_t> SizeTVector;
typedef std::deque<size_t> SizeTDeque;

// =============================================================================
// Defines

#define DECLARE_EXCEPTION(ExceptionName)          \
	class ExceptionName : public std::exception   \
	{                                             \
	public:                                       \
		virtual const char *what() const throw(); \
	};

#define IMPLEMENT_EXCEPTION(ExceptionName, message)           \
	const char *PmergeMe::ExceptionName::what() const throw() \
	{                                                         \
		return message;                                       \
	}

// =============================================================================
// Class PmergeMe

class PmergeMe
{

private:

	// =========================================================================
	// Variables

	// Original data
	IntVector _originalData;
	// First container Vector
	IntVector _vectorData;
	// Second container Deque
	IntDeque _dequeData;
	// Vector timing
	double _vectorTime;
	// Deque timing
	double _dequeTime;

	// =========================================================================
	// Private Handlers

	// Default Constructor
	PmergeMe(void);
	// Copy Constructor
	PmergeMe(const PmergeMe &other);
	// Assignation operator
	PmergeMe &operator=(const PmergeMe &other);

	// =========================================================================
	// Private Methods

	/**
	 * @brief Parse and validate input arguments
	 * @param ac Argument count
	 * @param av Argument vector
	 * @throws InvalidArgumentException if an argument is invalid
	 * @throws NegativeNumberException if a negative number is encountered
	 * @throws NonNumericArgumentException if a non-numeric argument is encountered
	 * @throws EmptyInputException if no input is provided
	 * @throws DuplicateNumberException if duplicate numbers are found
	 */
	void parseInput(int ac, char **av);

	/** Measure sorting time for both containers */
	void measureTime();

	/**
	 * @brief Generate a vector of Jacobsthal numbers up to maxSize
	 * @param maxSize Maximum size for Jacobsthal numbers
	 * @return Vector of Jacobsthal numbers
	 */
	SizeTVector generateJacobsthalVector(size_t maxSize) const;

	/**
	 * @brief Generate a deque of Jacobsthal numbers up to maxSize
	 * @param maxSize Maximum size for Jacobsthal numbers
	 * @return Deque of Jacobsthal numbers
	 */
	SizeTDeque generateJacobsthalDeque(size_t maxSize) const;

	/**
	 * @brief Generate optimal insertion order using Jacobsthal numbers (vector)
	 * @param nbElements Number of elements to generate order for
	 * @return Vector of indices in optimal insertion order
	 */
	SizeTVector generateJacobsthalOrderVector(size_t nbElements) const;

	/**
	 * @brief Generate optimal insertion order using Jacobsthal numbers (deque)
	 * @param nbElements Number of elements to generate order for
	 * @return Deque of indices in optimal insertion order
	 */
	SizeTDeque generateJacobsthalOrderDeque(size_t nbElements) const;

	/**
	 * @brief Create insertion order vector
	 * @param nbElements Number of elements to generate order for
	 * @return Vector of indices in optimal insertion order
	 */
	IntVector createInsertionOrderVector(size_t nbElements);

	/**
	 * @brief Create insertion order deque
	 * @param nbElements Number of elements to generate order for
	 * @return Deque of indices in optimal insertion order
	 */
	IntDeque createInsertionOrderDeque(size_t nbElements);\


	IntVector::iterator lowerBoundVector(IntVector::iterator first, IntVector::iterator last, int value);

	IntDeque::iterator lowerBoundDeque(IntDeque::iterator first, IntDeque::iterator last, int value);

	/**
	 * @brief Recursive sort helper for vector
	 * @param max Vector of maximum elements
	 * @param min Vector of minimum elements
	 */
	void sortRecursiveVector(IntVector &max, IntVector &min);

	/**
	 * @brief Recursive sort helper for deque
	 * @param max Deque of maximum elements
	 * @param min Deque of minimum elements
	 */
	void sortRecursiveDeque(IntDeque &max, IntDeque &min);

public:
	// =========================================================================
	// Handlers

	// Custom Constructor
	PmergeMe(int ac, char **av);
	// Destructor
	~PmergeMe(void);

	// =========================================================================
	// Getters

	/** Return original data */
	const IntVector getOriginalData() const;

	/** Return vector data */
	const IntVector getVectorData() const;

	/** Return deque data */
	const IntDeque getDequeData() const;

	/** Return time taken to sort vector */
	double getVectorTime() const;

	/** Return time taken to sort deque */
	double getDequeTime() const;

	// =========================================================================
	// Methods

	/** Sort using Ford-Johnson algorithm (vector) */
	void sortVector();

	/** Sort using Ford-Johnson algorithm (deque) */
	void sortDeque();

	/** Display sorting results */
	void displayResults();

	// =========================================================================
	// Exceptions

	// "Error: invalid argument"
	DECLARE_EXCEPTION(InvalidArgumentException)
	// "Error: negative numbers not allowed"
	DECLARE_EXCEPTION(NegativeNumberException)
	// "Error: non-numeric argument"
	DECLARE_EXCEPTION(NonNumericArgumentException)
	// "Error: no input provided"
	DECLARE_EXCEPTION(EmptyInputException)
	// "Error: duplicate number"
	DECLARE_EXCEPTION(DuplicateNumberException)
};

// =============================================================================
// Helper Template Struct

/**
 * @brief Comparator struct to compare indices based on values in a container
 * @tparam Container Type of the container holding the values
 */
template <typename Container>
struct IndexComparator
{
	const Container &values;

	/**
	 * @brief Constructor to initialize the comparator with a container reference
	 * @param v Reference to the container of values
	 */
	IndexComparator(const Container &v) : values(v) {}

	/**
	 * @brief Comparison operator to compare two indices based on their values
	 * @param i First index
	 * @param j Second index
	 * @return true if value at index i is less than value at index j, false otherwise
	 */
	bool operator()(size_t i, size_t j) const
	{
		return values[i] < values[j];
	}
};
