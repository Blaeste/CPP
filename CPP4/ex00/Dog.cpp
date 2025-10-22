/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:58 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:35:58 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

// Default Constructor
Dog::Dog() : Animal("Dog") {

	std::cout << "Dog Default Constructor called" << std::endl;
}

// String Constructor
Dog::Dog( std::string type ) : Animal(type) {

	std::cout << "Dog String Constructor called" << std::endl;
}

// Copy Constructor
Dog::Dog( const Dog &other ) : Animal(other._type) {

	std::cout << "Dog Copy Constructor called" << std::endl;
}

// Assignation operator
Dog &Dog::operator=(const Dog &other) {

	std::cout << "Dog Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
Dog::~Dog() {

	std::cout << "Dog Destructor called" << std::endl;
}

// Functions
void	Dog::makeSound( void ) const{

	std::cout << "Woof!" << std::endl;
}
