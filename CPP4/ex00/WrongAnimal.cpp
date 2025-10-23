/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:30:48 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 09:37:13 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

// Default Constructor
WrongAnimal::WrongAnimal() {

	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

// String Constructor
WrongAnimal::WrongAnimal( std::string const &type ) : _type(type) {

	std::cout << "WrongAnimal String Constructor called" << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal( const WrongAnimal &other ) : _type(other._type) {

	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

// Assignation operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {

	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal() {

	std::cout << "WrongAnimal Destructor called" << std::endl;
}


// Accessors
std::string	WrongAnimal::getType( void ) const {

	return this->_type;
}

// Functions
void	WrongAnimal::makeSound( void ) const {

	std::cout << "Some generic WrongAnimal sound" << std::endl;
}
