/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:33:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/12 10:13:40 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Bureaucrat;

class AForm {

	private:
		const std::string 	_name;
		bool				_signed;
		const unsigned int	_signGrade;
		const unsigned int	_execGrade;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		AForm( void );
		// Custom Constructor
		AForm( std::string const &name, unsigned int signGrade, unsigned int execGrade );
		// Copy Constructor
		AForm( const AForm &other );
		// Assignation operator
		AForm&operator=(const AForm &other);
		// Destructor
		virtual ~AForm( void );

		// =====================================================================
		// Getters

		std::string	getName( void ) const;
		bool getSigned( void ) const;
		unsigned int getSignGrade( void ) const;
		unsigned int getExecGrade( void ) const;

		// =====================================================================
		// Methods

		virtual void execute( Bureaucrat const &executor ) const = 0;

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

		class FormNotSigned : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "the form is not signed!";
				}
		};

};

// =============================================================================
// Operator overload

std::ostream &operator<<(std::ostream &os, const AForm &form);
