/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:23:47 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 11:29:08 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	private:
		std::string _target;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		PresidentialPardonForm( void );
		// String Constructor
		PresidentialPardonForm( std::string const &param );
		// Copy Constructor
		PresidentialPardonForm( const PresidentialPardonForm &other );
		// Assignation operator
		PresidentialPardonForm&operator=(const PresidentialPardonForm &other);
		// Destructor
		~PresidentialPardonForm( void );

		// =====================================================================
		// Getters

		// =====================================================================
		// Methods

		void	execute( Bureaucrat const &executor ) const;

		// =====================================================================
		// Exceptions

};

// =============================================================================
// Op overload
