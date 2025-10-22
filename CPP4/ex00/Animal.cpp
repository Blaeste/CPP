/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:47:14 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:33:33 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

// Default Constructor
Animal::Animal() : _type("") {

	std::cout << "Animal Default Constructor called" << std::endl;
}

// String Constructor
Animal::Animal( std::string type ) : _type(type) {

	std::cout << "Animal String Constructor called" << std::endl;
}

// Copy Constructor
Animal::Animal( const Animal &other ) : _type(other._type) {

	std::cout << "Animal Copy Constructor called" << std::endl;
}

// Assignation operator
Animal &Animal::operator=(const Animal &other) {

	std::cout << "Animal Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
Animal::~Animal() {

	std::cout << "Animal Destructor called" << std::endl;
}

// Accessors
std::string	Animal::getType( void ) const {

	return this->_type;
}

// Functions
void	Animal::makeSound( void ) const {

	std::cout << "Some generic animal sound" << std::endl;
}
