/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:15:23 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 09:52:35 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		// Default Constructor
		Cure( void );
		// String Constructor
		Cure( std::string const &param );
		// Copy Constructor
		Cure( const Cure &other );
		// Assignation operator
		Cure&operator=(const Cure &other);
		// Destructor
		virtual ~Cure( void );

		// Accessors

		// Functions
		virtual AMateria *clone( void ) const;
		virtual void use( ICharacter &target ) const;
};
