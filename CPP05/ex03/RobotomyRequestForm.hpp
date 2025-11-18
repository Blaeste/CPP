/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:24:47 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/03 10:36:26 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	private:
		std::string _target;

	public:

		// =====================================================================
		// Handlers

		// Default Constructor
		RobotomyRequestForm( void );
		// String Constructor
		RobotomyRequestForm( std::string const &target );
		// Copy Constructor
		RobotomyRequestForm( const RobotomyRequestForm &other );
		// Assignation operator
		RobotomyRequestForm&operator=(const RobotomyRequestForm &other);
		// Destructor
		~RobotomyRequestForm( void );

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
