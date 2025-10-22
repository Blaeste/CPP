/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:53:29 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:33:36 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {

	public:
		// Default Constructor
		Dog( void );
		// String Constructor
		Dog( std::string type );
		// Copy Constructor
		Dog( const Dog &other );
		// Assignation operator
		Dog&operator=(const Dog &other);
		// Destructor
		~Dog();

		// Accessors

		// Functions
		void	makeSound( void ) const;
};
