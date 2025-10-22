/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:18:47 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:09:24 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {

	private:
		std::string	_name;
		AMateria	*_inventory[4];
		AMateria	*_floor[10];

	public:
		// Default Constructor
		Character( void );
		// String Constructor
		Character( std::string const &name );
		// Copy Constructor
		Character( const Character &other );
		// Assignation operator
		Character&operator=(const Character &other);
		// Destructor
		virtual ~Character( void );

		// Accessors
		virtual std::string const &getName( void ) const;

		// Functions
		virtual void equip( AMateria *m );
		virtual void unequip( int idx);
		virtual void use(int idx, ICharacter &target );
};
