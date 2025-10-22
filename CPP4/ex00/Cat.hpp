/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:17 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:33:39 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {

	public:
		// Default Constructor
		Cat( void );
		// String Constructor
		Cat( std::string type );
		// Copy Constructor
		Cat( const Cat &other );
		// Assignation operator
		Cat&operator=(const Cat &other);
		// Destructor
		~Cat();

		// Accessors

		// Functions
		void	makeSound( void ) const;
};
