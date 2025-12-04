/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:10:49 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/04 09:59:33 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <sstream>

// ============================================================================
// Handlers

// Default Constructor
RPN::RPN() {}

// Custom Constructor
RPN::RPN( std::string const &input ) {

	calculate(input);
}

// Copy Constructor
RPN::RPN( const RPN &other ) :
	_stack(other._stack) {}

// Assignation operator
RPN &RPN::operator=(const RPN &other) {

	if ( this != &other )
		this->_stack = other._stack;

	return *this;
}

// Destructor
RPN::~RPN() {}

// =============================================================================
// Methods

bool RPN::isOperator(char c) {

	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isNumber(char c) {

	return (c >= '0' && c <= '9');
}

int RPN::performOperation(int a, int b, char op) {

	long long result;

	switch (op) {

		case '+':
			result = static_cast<long long>(a) + static_cast<long long>(b);
			if (result > 2147483647 || result < -2147483648)
				throw OverflowException();
			return static_cast<int>(result);

		case '-':
			result = static_cast<long long>(a) - static_cast<long long>(b);
			if (result > 2147483647 || result < -2147483648)
				throw OverflowException();
			return static_cast<int>(result);

		case '*':
			result = static_cast<long long>(a) * static_cast<long long>(b);
			if (result > 2147483647 || result < -2147483648)
				throw OverflowException();
			return static_cast<int>(result);

		case '/':
			if ( b == 0)
				throw DivisionByZeroException();
			if ( a % b != 0)
				throw NonIntegerResultException();
			return a / b;

		default: throw InvalidOperatorException();
	}
}

void RPN::calculate(const std::string &input) {

	// ccreate a read flux
	std::istringstream iss(input);
	std::string token;

	while ( iss >> token ) {

		// Check if number and push it
		if ( token.length() == 1 && isNumber(token[0]))
			_stack.push(token[0] - '0');

		// Check operator
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if ( this->_stack.size() < 2 )
				throw InsufficientOperandsException();

			// get number and remove from stack
			int b = _stack.top();
			this->_stack.pop();
			int a = _stack.top();
			this->_stack.pop();

			// Do the op
			int result = performOperation(a, b, token[0]);

			// store it on top of the stack
			_stack.push(result);
		}

		else
			throw NotADigitException();
	}

	// Check only one element in stack
	if ( this->_stack.size() != 1 )
		throw InvalidExpressionException();

	// Output
	std::cout << _stack.top() << std::endl;
}

// =============================================================================
// Exceptions

IMPLEMENT_EXCEPTION(InsufficientOperandsException, "Error: not enough operands for operation.")
IMPLEMENT_EXCEPTION(InvalidExpressionException, "Error: invalid expression (too many operands).")
IMPLEMENT_EXCEPTION(NotADigitException, "Error: invalid token (only single digits 0-9 and operators +, -, *, / are allowed).")
IMPLEMENT_EXCEPTION(InvalidOperatorException, "Error: invalid operator.")
IMPLEMENT_EXCEPTION(DivisionByZeroException, "Error: division by zero.")
IMPLEMENT_EXCEPTION(OverflowException, "Error: arithmetic overflow detected.")
IMPLEMENT_EXCEPTION(NonIntegerResultException, "Error: division does not result in an integer (no rounding applied).")
