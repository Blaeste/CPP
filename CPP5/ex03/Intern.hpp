/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:16:06 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 13:21:36 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AForm.hpp"

class Intern {

	private:

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		Intern( void );
		// String Constructor
		Intern( std::string const &param );
		// Copy Constructor
		Intern( const Intern &other );
		// Assignation operator
		Intern&operator=(const Intern &other);
		// Destructor
		~Intern( void );

		// =====================================================================
		// Getters

		// =====================================================================
		// Methods

		AForm *makeForm( std::string formName, std::string formTarget );
		// =====================================================================
		// Exceptions

};

// =============================================================================
// Op overload
