/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:43:56 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:31:15 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

// Default Constructor
Brain::Brain() {

	for ( int i = 0; i < 100; i++ ) {

		this->_ideas[i] = "Default idea";
	}
	std::cout << "Brain Default Constructor called" << std::endl;
}

// String Constructor
Brain::Brain( std::string type ) {

	for ( int i = 0; i < 100; i++ ) {

		this->_ideas[i] = "I am a " + type;
	}
	std::cout << "Brain String Constructor called" << std::endl;
}

// Copy Constructor
Brain::Brain( const Brain &other ) {

	for ( int i = 0; i < 100; i++ ) {

		this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain Copy Constructor called" << std::endl;
}

// Assignation operator
Brain &Brain::operator=(const Brain &other) {

	std::cout << "Brain Assignation operator called" << std::endl;
	if ( this != &other ) {

		for ( int i = 0; i < 100; i++ ) {

			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

// Destructor
Brain::~Brain() {

	std::cout << "Brain Destructor called" << std::endl;
}


// Accessors
std::string	Brain::getIdea( int index ) const {

	if ( index >= 0 && index < 100 ) {

		return this->_ideas[index];
	}
	return "";
}
