/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:47:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:46:21 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AAnimal {

	protected:
		std::string	_type;

	public:
		// Default Constructor
		AAnimal( void );
		// String Constructor
		AAnimal( std::string type );
		// Copy Constructor
		AAnimal( const AAnimal &other );
		// Assignation operator
		AAnimal&operator=(const AAnimal &other);
		// Destructor
		virtual ~AAnimal();

		// Accessors
		std::string	getType( void ) const;

		// Functions
		virtual void makeSound( void ) const = 0;
};
