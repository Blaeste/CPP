/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:30:50 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 09:36:47 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal {

	protected:
		std::string	_type;

	public:
		// Default Constructor
		WrongAnimal( void );
		// String Constructor
		WrongAnimal( std::string const &type );
		// Copy Constructor
		WrongAnimal( const WrongAnimal &other );
		// Assignation operator
		WrongAnimal&operator=(const WrongAnimal &other);
		// Destructor
		~WrongAnimal( void );

		// Accessors
		std::string	getType( void ) const;

		// Functions
		virtual void makeSound( void ) const;
};
