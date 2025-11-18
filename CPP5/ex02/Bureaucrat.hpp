/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:50:02 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 11:21:52 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <iostream>

#include "AForm.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		Bureaucrat( void );
		// Custom Constructor
		Bureaucrat( std::string const &name, int grade );
		// Copy Constructor
		Bureaucrat( const Bureaucrat &other );
		// Assignation operator
		Bureaucrat&operator=(const Bureaucrat &other);
		// Destructor
		~Bureaucrat( void );

		// =====================================================================
		// Getters

		const std::string	getName( void ) const;
		unsigned int		getGrade( void ) const;

		// =====================================================================
		// Methods

		void incrementGrade( void ); // warning here 1 > 150
		void decrementGrade( void ); // so need to do the other way
		void signForm( AForm &form );
		void executeForm( AForm &form );


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

		class BureaucratNameEmpty : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "the bureaucrat name is empty!";
				}
		};
};

// =============================================================================
// Operator overload

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
