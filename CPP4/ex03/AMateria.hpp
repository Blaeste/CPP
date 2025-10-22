/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:17:20 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 13:23:26 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter; // Forward Decl

class AMateria
{
	protected:
		std::string _type;

	public:
		// Default Constructor
		AMateria( void );
		// String Constructor
		AMateria( std::string const &type );
		// Copy Constructor
		AMateria( const AMateria &other );
		// Assignation operator
		AMateria&operator=(const AMateria &other);
		// Destructor
		virtual ~AMateria( void );

		// Accessors
		virtual std::string const &getType() const;

		// Functions
		virtual AMateria *clone( void ) const = 0;
		virtual void use( ICharacter &target) const = 0;
};
