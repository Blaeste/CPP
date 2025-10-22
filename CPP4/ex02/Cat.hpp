/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:17 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:41:09 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

	private:
		Brain *_brain;

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
		std::string	getBrainIdea( int index ) const;

		// Functions
		void	makeSound( void ) const;
		void	newBrain( std::string type );
};
