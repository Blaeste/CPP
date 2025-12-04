/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:11:05 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/04 09:59:40 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =============================================================================
// Includes

#pragma once
#include <string>
#include <stack>
#include <stdexcept>

// =============================================================================
// Defines

#define DECLARE_EXCEPTION(ExceptionName)          \
	class ExceptionName : public std::exception   \
	{                                             \
	public:                                       \
		virtual const char *what() const throw(); \
	};

#define IMPLEMENT_EXCEPTION(ExceptionName, message)      \
	const char *RPN::ExceptionName::what() const throw() \
	{                                                    \
		return message;                                  \
	}

// =============================================================================
// Class RPN

class RPN {

	private:

		// Stack container
		std::stack<int> _stack;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		RPN( void );
		// Custom Constructor
		RPN( std::string const &input );
		// Copy Constructor
		RPN( const RPN &other );
		// Assignation operator
		RPN&operator=(const RPN &other);
		// Destructor
		~RPN( void );

		// =====================================================================
		// Methods

		bool isOperator(char c);
		bool isNumber(char c);

		int performOperation(int a, int b, char op);
		void calculate(const std::string &input);

		// =====================================================================
		// Exceptions

		DECLARE_EXCEPTION(InsufficientOperandsException)
		DECLARE_EXCEPTION(InvalidExpressionException)
		DECLARE_EXCEPTION(NotADigitException)
		DECLARE_EXCEPTION(InvalidOperatorException)
		DECLARE_EXCEPTION(DivisionByZeroException)
		DECLARE_EXCEPTION(OverflowException)
		DECLARE_EXCEPTION(NonIntegerResultException)
};

// =============================================================================
// Op overload
