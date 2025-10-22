/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:53:29 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:41:13 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain *_brain;

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
		std::string	getBrainIdea( int index ) const;

		// Functions
		void	makeSound( void ) const;
		void	newBrain( std::string type );
};
