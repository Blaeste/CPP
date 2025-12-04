/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:54:41 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/04 10:23:02 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =============================================================================
// Includes
// =============================================================================

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cerrno>
#include <climits>

// =============================================================================
// Handlers
// =============================================================================

// Custom Constructor
PmergeMe::PmergeMe(int ac, char **av) : _vectorTime(0.0),
										_dequeTime(0.0)
{
	parseInput(ac, av);
	measureTime();
}

// Destructor
PmergeMe::~PmergeMe() {}

// =============================================================================
// Getters
// =============================================================================

const IntVector PmergeMe::getOriginalData() const
{
	return _originalData;
}

const IntVector PmergeMe::getVectorData() const
{
	return _vectorData;
}

const IntDeque PmergeMe::getDequeData() const
{
	return _dequeData;
}

double PmergeMe::getVectorTime() const
{
	return _vectorTime;
}

double PmergeMe::getDequeTime() const
{
	return _dequeTime;
}

// =============================================================================
// Methods
// =============================================================================

void PmergeMe::parseInput(int ac, char **av)
{
	// Check not empty
	if (ac < 2)
		throw EmptyInputException();

	// Parse input
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];

		// Check if starts with sign
		size_t startPos = 0;
		if (arg[0] == '+' || arg[0] == '-')
		{
			if (arg[0] == '-')
				throw NegativeNumberException();
			startPos = 1;
		}

		// Check all remaining characters are digits
		if (startPos >= arg.length())
			throw NonNumericArgumentException();

		for (size_t j = startPos; j < arg.length(); ++j)
		{
			if (!isdigit(arg[j]))
				throw NonNumericArgumentException();
		}

		// Parse and validate numeric argument
		char *endptr;
		errno = 0;
		long number = std::strtol(av[i], &endptr, 10);

		// Check for conversion errors
		if (*endptr != '\0')
			throw NonNumericArgumentException();

		// Check for overflow/underflow
		if (errno == ERANGE || number > 2147483647 || number < 0)
			throw InvalidArgumentException();

		_originalData.push_back(static_cast<int>(number));
	}

	// Check for duplicates
	for (size_t i = 0; i < _originalData.size(); ++i)
		for (size_t j = i + 1; j < _originalData.size(); ++j)
			if (_originalData[i] == _originalData[j])
				throw DuplicateNumberException();

	// Fill vector
	_vectorData = _originalData;

	// Fill deque
	_dequeData.assign(_originalData.begin(), _originalData.end());
}

// =============================================================================
// Jacobsthal (vector)
// =============================================================================

SizeTVector PmergeMe::generateJacobsthalVector(size_t nbElements) const
{
	SizeTVector jacobsthal;

	// Base cases
	if (nbElements == 0) return jacobsthal;

	jacobsthal.push_back(0);

	if (nbElements == 1) return jacobsthal;

	jacobsthal.push_back(1);

	while (1)
	{
		// Jacobsthal recurrence: J(n) = J(n - 1) + 2 * J(n - 2)
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
		// Stop when exceeding target size + 1 (one extra for grouping logic)
		if (next > nbElements) break;
	}

	return jacobsthal; // 0 1 1 3 5 11 21 43 ...
}

SizeTVector PmergeMe::generateJacobsthalOrderVector(size_t nbElements) const
{
	// Get jacobsthal values
	SizeTVector jacobsthal = generateJacobsthalVector(nbElements);

	SizeTVector order;

	// Process each Jacobsthal interval to build insertion order
	for (size_t i = 1; i < jacobsthal.size(); ++i)
	{
		// Define group boundaries between consecutive Jacobsthal numbers
		size_t groupStart = jacobsthal[i - 1] + 1;
		size_t groupEnd = jacobsthal[i];

		// Insert elements in descending order within group
		// Cap at nbElements to avoid out of bound
		size_t start = groupEnd;
		if (start > nbElements)
			start = nbElements;

		for (size_t j = start; j >= groupStart; --j)
		{
			order.push_back(j);

			// Prevent underflow when j reaches 0
			if (j == 0)
				break;
		}
	}

	// Add any remaining elements not covered by Jacobsthal groups
	size_t lastProcessed = (jacobsthal.size() > 1) ? jacobsthal[jacobsthal.size() - 2] : 0;
	for (size_t j = lastProcessed + 1; j <= nbElements; ++j)
	{
		bool already_added = false;
		for (size_t k = 0; k < order.size(); ++k)
		{
			if (order[k] == j)
			{
				already_added = true;
				break;
			}
		}
		if (!already_added)
			order.push_back(j);
	}

	return order;
}

IntVector PmergeMe::createInsertionOrderVector(size_t nbElements)
{
	// get indices in optimal insert order
	SizeTVector order = generateJacobsthalOrderVector(nbElements);

	IntVector indices;

	// convert to int and adjust from 1-based to 0-based indexing
	for (size_t i = 0; i < order.size(); ++i)
		if (order[i] > 0 && order[i] <= nbElements)
			indices.push_back(order[i] - 1);

	return indices;
}

// =============================================================================
// Jacobsthal (deque)
// =============================================================================

SizeTDeque PmergeMe::generateJacobsthalDeque(size_t nbElements) const
{
	SizeTDeque jacobsthal;

	// Base cases
	if (nbElements == 0) return jacobsthal;

	jacobsthal.push_back(0);

	if (nbElements == 1) return jacobsthal;

	jacobsthal.push_back(1);

	while (1)
	{
		// Jacobsthal recurrence: J(n) = J(n - 1) + 2 * J(n - 2)
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
		// Stop when exceeding target size + 1 (one extra for grouping logic)
		if (next > nbElements) break;
	}

	return jacobsthal; // 0 1 1 3 5 11 21 43 ...
}

SizeTDeque PmergeMe::generateJacobsthalOrderDeque(size_t nbElements) const
{
	// Get jacobsthal values
	SizeTDeque jacobsthal = generateJacobsthalDeque(nbElements);

	SizeTDeque order;

	// Process each Jacobsthal interval to build insertion order
	for (size_t i = 1; i < jacobsthal.size(); ++i)
	{
		// Define group boundaries between consecutive Jacobsthal numbers
		size_t groupStart = jacobsthal[i - 1] + 1;
		size_t groupEnd = jacobsthal[i];

		// Insert elements in descending order within group
		// Cap at nbElements to avoid out of bound
		size_t start = groupEnd;
		if (start > nbElements)
			start = nbElements;

		for (size_t j = start; j >= groupStart; --j)
		{
			order.push_back(j);

			// Prevent underflow when j reaches 0
			if (j == 0) break;
		}
	}

	// Add any remaining elements not covered by Jacobsthal groups
	size_t lastProcessed = (jacobsthal.size() > 1) ? jacobsthal[jacobsthal.size() - 2] : 0;
	for (size_t j = lastProcessed + 1; j <= nbElements; ++j)
	{
		bool already_added = false;
		for (size_t k = 0; k < order.size(); ++k)
		{
			if (order[k] == j)
			{
				already_added = true;
				break;
			}
		}
		if (!already_added)
			order.push_back(j);
	}

	return order;
}

IntDeque PmergeMe::createInsertionOrderDeque(size_t nbElements)
{
	// get indices in optimal insert order
	SizeTDeque order = generateJacobsthalOrderDeque(nbElements);

	IntDeque indices;

	// convert to int and adjust from 1-based to 0-based indexing
	for (size_t i = 0; i < order.size(); ++i)
		if (order[i] > 0 && order[i] <= nbElements)
			indices.push_back(order[i] - 1);

	return indices;
}

// =============================================================================
// Ford-Johnson Algorithm (vector)
// =============================================================================

IntVector::iterator PmergeMe::lowerBoundVector(IntVector::iterator first, IntVector::iterator last, int value)
{
	IntVector::iterator it;
	int count = std::distance(first, last);

	while (count > 0)
	{
		it  = first;
		int step = count / 2;
		std::advance(it, step);

		if (*it < value)
		{
			first = it;
			++first;
			count -= step + 1;
		}

		else
			count = step;
	}
	return first;
}

void PmergeMe::sortRecursiveVector(IntVector &maxElements, IntVector &minElements)
{
	// Base case: nothing to sort if 0 or 1 element
	if (maxElements.size() <= 1) return;

	IntVector winners, losers, winnerMins, loserMins;

	// Opti .reserve only on vector
	winners.reserve(maxElements.size() / 2 + 1);
	losers.reserve(maxElements.size() / 2 + 1);
	winnerMins.reserve(maxElements.size() / 2 + 1);
	loserMins.reserve(maxElements.size() / 2 + 1);

	// Step 1: Create pairs and separate winners (larger) from losers (smaller)
	// Winners will be sorted recursively, losers will be inserted later
	for (size_t i = 0; i < maxElements.size(); i += 2)
	{
		if (i + 1 < maxElements.size())
		{
			if (maxElements[i] > maxElements[i + 1])
			{
				winners.push_back(maxElements[i]);
				winnerMins.push_back(minElements[i]);
				losers.push_back(maxElements[i + 1]);
				loserMins.push_back(minElements[i + 1]);
			}
			else
			{
				winners.push_back(maxElements[i + 1]);
				winnerMins.push_back(minElements[i + 1]);
				losers.push_back(maxElements[i]);
				loserMins.push_back(minElements[i]);
			}
		}
		else
		{
			// Odd element: unpaired element becomes a loser for later insertion
			losers.push_back(maxElements[i]);
			loserMins.push_back(minElements[i]);
		}
	}

	// Step 2: Recursively sort the winners chain
	sortRecursiveVector(winners, winnerMins);

	// Update maxElements with sorted winners
	// (maintaining correspondence with minElements)
	maxElements = winners;
	minElements = winnerMins;

	// Step 3: Binary insert losers into sorted chain

	IntVector order = createInsertionOrderVector(losers.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t index = order[k];

		if (index < losers.size())
		{
			int val = losers[index];
			int minVal = loserMins[index];

			// Find position of corresponding max element (right bound for search)
			IntVector::iterator maxPos = std::find(maxElements.begin(), maxElements.end(), maxElements[index]);

			// Binary search only up to the corresponding max position
			IntVector::iterator itPos = lowerBoundVector(maxElements.begin(), maxPos + 1, val);

			size_t pos = std::distance(maxElements.begin(), itPos);

			maxElements.insert(maxElements.begin() + pos, val);
			minElements.insert(minElements.begin() + pos, minVal);
		}
	}
}

void PmergeMe::sortVector()
{
	if (_vectorData.size() <= 1) return;

	// =========================================================================
	// Step 1: Initial pairing from raw input

	bool hasOddElement = false;
	int oddElement = 0;
	IntVector maxElements, minElements;

	// Create pairs from input: separate larger (max) from smaller (min) elements
	for (size_t i = 0; i < _vectorData.size(); i += 2)
	{
		if (i + 1 < _vectorData.size())
		{
			if (_vectorData[i] > _vectorData[i + 1])
			{
				maxElements.push_back(_vectorData[i]);
				minElements.push_back(_vectorData[i + 1]);
			}
			else
			{
				maxElements.push_back(_vectorData[i + 1]);
				minElements.push_back(_vectorData[i]);
			}
		}
		else
		{
			hasOddElement = true;
			oddElement = _vectorData[i];
		}
	}

	// =========================================================================
	// Step 2: Recursively sort the max elements chain

	sortRecursiveVector(maxElements, minElements);

	// =========================================================================
	// Step 3: Build initial sorted sequence
	// Start with first min (smallest overall) followed by all sorted max elements

	_vectorData.clear();

	// if (!minElements.empty())
	// 	_vectorData.push_back(minElements[0]);

	for (size_t i = 0; i < maxElements.size(); ++i)
		_vectorData.push_back(maxElements[i]);

	// =========================================================================
	// Step 4: Insert remaining min elements using Jacobsthal sequence
	// This order minimizes the number of comparisons needed

	IntVector order = createInsertionOrderVector(minElements.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		int index = order[i];

		if (index >= 0 && index < static_cast<int>(minElements.size()))
		{
			// Find position of corresponding max element (right bound)
			IntVector::iterator maxPos = std::find(_vectorData.begin(), _vectorData.end(), maxElements[index]);

			// Binary search only up to the corresponding max position
			IntVector::iterator pos = lowerBoundVector(_vectorData.begin(), maxPos + 1, minElements[index]);

			_vectorData.insert(pos, minElements[index]);
		}
	}

	// =========================================================================
	// Step 5: Insert odd element (if exists) using binary search

	if (hasOddElement)
	{
		IntVector::iterator pos = lowerBoundVector(
			_vectorData.begin(), _vectorData.end(), oddElement);

		_vectorData.insert(pos, oddElement);
	}
	// ALED WTF IS THAT...
}

// =============================================================================
// Ford-Johnson Algorithm (deque)
// =============================================================================

IntDeque::iterator PmergeMe::lowerBoundDeque(IntDeque::iterator first, IntDeque::iterator last, int value)
{
	IntDeque::iterator it;
	int count = std::distance(first, last);

	while (count > 0)
	{
		it  = first;
		int step = count / 2;
		std::advance(it, step);

		if (*it < value)
		{
			first = it;
			++first;
			count -= step + 1;
		}

		else
			count = step;
	}
	return first;
}

void PmergeMe::sortRecursiveDeque(IntDeque &maxElements, IntDeque &minElements)
{
	// Base case: nothing to sort if 0 or 1 element
	if (maxElements.size() <= 1) return;

	IntDeque winners, losers, winnerMins, loserMins;

	// Step 1: Create pairs and separate winners (larger) from losers (smaller)
	// Winners will be sorted recursively, losers will be inserted later
	for (size_t i = 0; i < maxElements.size(); i += 2)
	{
		if (i + 1 < maxElements.size())
		{
			if (maxElements[i] > maxElements[i + 1])
			{
				winners.push_back(maxElements[i]);
				winnerMins.push_back(minElements[i]);
				losers.push_back(maxElements[i + 1]);
				loserMins.push_back(minElements[i + 1]);
			}
			else
			{
				winners.push_back(maxElements[i + 1]);
				winnerMins.push_back(minElements[i + 1]);
				losers.push_back(maxElements[i]);
				loserMins.push_back(minElements[i]);
			}
		}
		else
		{
			// Odd element: unpaired element becomes a loser for later insertion
			losers.push_back(maxElements[i]);
			loserMins.push_back(minElements[i]);
		}
	}

	// Step 2: Recursively sort the winners chain
	sortRecursiveDeque(winners, winnerMins);

	// Update maxElements with sorted winners
	// (maintaining correspondence with minElements)
	maxElements = winners;
	minElements = winnerMins;

	// Step 3: Binary insert losers into sorted chain

	IntDeque order = createInsertionOrderDeque(losers.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t index = order[k];

		if (index < losers.size())
		{
			int val = losers[index];
			int minVal = loserMins[index];

			// Find position of corresponding max element (right bound for search)
			IntDeque::iterator maxPos = std::find(maxElements.begin(), maxElements.end(), maxElements[index]);

			// Binary search only up to the corresponding max position
			IntDeque::iterator itPos = lowerBoundDeque(maxElements.begin(), maxPos + 1, val);

			size_t pos = std::distance(maxElements.begin(), itPos);

			maxElements.insert(maxElements.begin() + pos, val);
			minElements.insert(minElements.begin() + pos, minVal);
		}
	}
}

void PmergeMe::sortDeque()
{
	if (_dequeData.size() <= 1) return;

	// =========================================================================
	// Step 1: Initial pairing from raw input

	bool hasOddElement = false;
	int oddElement = 0;
	IntDeque maxElements, minElements;

	// Create pairs from input: separate larger (max) from smaller (min) elements
	for (size_t i = 0; i < _dequeData.size(); i += 2)
	{
		if (i + 1 < _dequeData.size())
		{
			if (_dequeData[i] > _dequeData[i + 1])
			{
				maxElements.push_back(_dequeData[i]);
				minElements.push_back(_dequeData[i + 1]);
			}
			else
			{
				maxElements.push_back(_dequeData[i + 1]);
				minElements.push_back(_dequeData[i]);
			}
		}
		else
		{
			hasOddElement = true;
			oddElement = _dequeData[i];
		}
	}

	// =========================================================================
	// Step 2: Recursively sort the max elements chain

	sortRecursiveDeque(maxElements, minElements);

	// =========================================================================
	// Step 3: Build initial sorted sequence
	// Start with first min (smallest overall) followed by all sorted max elements

	_dequeData.clear();

	// if (!minElements.empty())
	// 	_dequeData.push_back(minElements[0]);

	for (size_t i = 0; i < maxElements.size(); ++i)
		_dequeData.push_back(maxElements[i]);

	// =========================================================================
	// Step 4: Insert remaining min elements using Jacobsthal sequence
	// This order minimizes the number of comparisons needed

	IntDeque order = createInsertionOrderDeque(minElements.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		int index = order[i];


		if (index >= 0 && index < static_cast<int>(minElements.size()))
		{
			// Find position of corresponding max element (right bound)
			IntDeque::iterator maxPos = std::find(_dequeData.begin(), _dequeData.end(), maxElements[index]);

			// Binary search only up to the corresponding max position
			IntDeque::iterator pos = lowerBoundDeque(_dequeData.begin(), maxPos + 1, minElements[index]);

			_dequeData.insert(pos, minElements[index]);
		}
	}

	// =========================================================================
	// Step 5: Insert odd element (if exists) using binary search

	if (hasOddElement)
	{
		IntDeque::iterator pos = lowerBoundDeque(
			_dequeData.begin(), _dequeData.end(), oddElement);

		_dequeData.insert(pos, oddElement);
	}
	// ALED WTF IS THAT...
}

// =============================================================================
// Other methods
// =============================================================================

void PmergeMe::measureTime()
{
	// Measure vector sorting time
	clock_t start = clock();
	sortVector();
	clock_t end = clock();

	_vectorTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

	// Measure deque sorting time
	start = clock();
	sortDeque();
	end = clock();

	_dequeTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::displayResults()
{
	std::cout << "Before: ";

	for (size_t i = 0; i < _originalData.size(); ++i)
	{
		std::cout << _originalData[i];

		if (i < _originalData.size() - 1)
			std::cout << " ";
	}

	std::cout << std::endl;

	std::cout << "After: ";

	for (size_t i = 0; i < _vectorData.size(); ++i)
	{
		std::cout << _vectorData[i];

		if (i < _vectorData.size() - 1)
			std::cout << " ";
	}

	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vectorData.size()
			  << " elements with std::vector : " << _vectorTime << " us\n";

	std::cout << "Time to process a range of " << _dequeData.size()
			  << " elements with std::deque : " << _dequeTime << " us\n";
}

// =============================================================================
// Exceptions
// =============================================================================

IMPLEMENT_EXCEPTION(InvalidArgumentException, "Error: invalid argument.")

IMPLEMENT_EXCEPTION(NegativeNumberException, "Error: negative numbers not allowed.")

IMPLEMENT_EXCEPTION(NonNumericArgumentException, "Error: non-numeric argument.")

IMPLEMENT_EXCEPTION(EmptyInputException, "Error: no input provided.")

IMPLEMENT_EXCEPTION(DuplicateNumberException, "Error: duplicate number in input.")
