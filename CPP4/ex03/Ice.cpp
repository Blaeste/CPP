/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:27:18 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:25:42 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"
#include <iostream>

// Default Constructor
Ice::Ice() : AMateria("ice") {

	//std::cout << "Ice Default Constructor called" << std::endl;
}

// String Constructor
Ice::Ice( std::string const &strVar ) : AMateria(strVar) {

	//std::cout << "Ice String Constructor called" << std::endl;
}

// Copy Constructor
Ice::Ice( const Ice &other ) : AMateria(other._type) {

	//std::cout << "Ice Copy Constructor called" << std::endl;
}

// Assignation operator
Ice &Ice::operator=(const Ice &other) {

	//std::cout << "Ice Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
Ice::~Ice() {

	//std::cout << "Ice Destructor called" << std::endl;
}

// Accessors

// Functions
AMateria *Ice::clone( void )const {

	return new Ice(*this);
}

void Ice::use( ICharacter &target ) const {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
