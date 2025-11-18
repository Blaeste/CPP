/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:33:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 11:22:28 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Bureaucrat;

class Form {
	private:
		const std::string 	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		Form( void );
		// Custom Constructor
		Form( std::string const &name, unsigned int signGrade, unsigned int execGrade );
		// Copy Constructor
		Form( const Form &other );
		// Assignation operator
		Form&operator=(const Form &other);
		// Destructor
		~Form( void );

		// =====================================================================
		// Getters

		std::string	getName( void ) const;
		bool getSigned( void ) const;
		unsigned int getSignGrade( void ) const;
		unsigned int getExecGrade( void ) const;

		// =====================================================================
		// Methods

		void beSigned( Bureaucrat b );

		// =====================================================================
		// Exceptions

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Grade is too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Grade is too low!";
				}
		};

		class FormNameEmpty : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "the form name is empty!";
				}
		};

		class FormAlreadySigned : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "the form is allready signed!";
				}
		};

};

// =============================================================================
// Operator overload

std::ostream &operator<<(std::ostream &os, const Form &form);
