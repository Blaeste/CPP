/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:27:11 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 09:56:57 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		// Default Constructor
		Ice( void );
		// String Constructor
		Ice( std::string const &param );
		// Copy Constructor
		Ice( const Ice &other );
		// Assignation operator
		Ice&operator=(const Ice &other);
		// Destructor
		virtual ~Ice( void );

		// Accessors

		// Functions
		virtual AMateria *clone( void ) const;
		virtual void use( ICharacter &target ) const;
};
