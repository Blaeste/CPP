/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:47:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:33:28 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {

	protected:
		std::string	_type;

	public:
		// Default Constructor
		Animal( void );
		// String Constructor
		Animal( std::string type );
		// Copy Constructor
		Animal( const Animal &other );
		// Assignation operator
		Animal&operator=(const Animal &other);
		// Destructor
		virtual ~Animal();

		// Accessors
		std::string	getType( void ) const;

		// Functions
		virtual void makeSound( void ) const;

};
