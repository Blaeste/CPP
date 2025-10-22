/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:31 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:40:56 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

// Default Constructor
Cat::Cat() : AAnimal("Cat") {

	Cat::newBrain("Cat");
	std::cout << "Cat Default Constructor called" << std::endl;
}

// String Constructor
Cat::Cat( std::string type ) : AAnimal(type) {

	Cat::newBrain(type);
	std::cout << "Cat String Constructor called" << std::endl;
}

// Copy Constructor
Cat::Cat( const Cat &other ) : AAnimal(other._type) {

	this->_brain = new Brain(*other._brain);
	std::cout << "Cat Copy Constructor called" << std::endl;
}

// Assignation operator
Cat &Cat::operator=(const Cat &other) {

	std::cout << "Cat Assignation operator called" << std::endl;
	if ( this != &other ) {

		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	return *this;
}

// Destructor
Cat::~Cat() {

	delete this->_brain;
	std::cout << "Cat Destructor called" << std::endl;
}

// Accessors
std::string	Cat::getBrainIdea( int index ) const {

	return this->_brain->getIdea(index);
}

// Functions
void	Cat::makeSound( void ) const {

	std::cout << "Meow!" << std::endl;
}

void	Cat::newBrain( std::string type ) {

	this->_brain = new Brain(type);
}

