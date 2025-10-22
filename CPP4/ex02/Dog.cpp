/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:58 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:41:18 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

// Default Constructor
Dog::Dog() : AAnimal("Dog") {

	Dog::newBrain("Dog");
	std::cout << "Dog Default Constructor called" << std::endl;
}

// String Constructor
Dog::Dog( std::string type ) : AAnimal(type) {

	Dog::newBrain(type);
	std::cout << "Dog String Constructor called" << std::endl;
}

// Copy Constructor
Dog::Dog( const Dog &other ) : AAnimal(other._type) {


	this->_brain = new Brain(*other._brain);
	std::cout << "Dog Copy Constructor called" << std::endl;
}

// Assignation operator
Dog &Dog::operator=(const Dog &other) {

	std::cout << "Dog Assignation operator called" << std::endl;
	if ( this != &other ) {

		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	return *this;
}

// Destructor
Dog::~Dog() {

	delete this->_brain;
	std::cout << "Dog Destructor called" << std::endl;
}

// Accessors
std::string	Dog::getBrainIdea( int index ) const {

	return this->_brain->getIdea(index);
}

// Functions
void	Dog::makeSound( void ) const{

	std::cout << "Woof!" << std::endl;
}

void	Dog::newBrain( std::string type ) {

	this->_brain = new Brain(type);
}

