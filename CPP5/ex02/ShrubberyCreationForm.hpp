/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:12:25 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/30 13:47:24 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

	private:
		std::string _target;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		ShrubberyCreationForm( void );
		// String Constructor
		ShrubberyCreationForm( std::string const &target );
		// Copy Constructor
		ShrubberyCreationForm( const ShrubberyCreationForm &other );
		// Assignation operator
		ShrubberyCreationForm&operator=(const ShrubberyCreationForm &other);
		// Destructor
		~ShrubberyCreationForm( void );

		// =====================================================================
		// Getters

		// =====================================================================
		// Methods

		void	execute( Bureaucrat const &executor ) const;

		// =====================================================================
		// Exceptions

		class ShrubberyFileCreation : public std::exception {
		public:
			virtual const char * what() const throw() {
				return "Shrubbery file fail de be created.";
			}
		};

};

// =============================================================================
// Op overload
