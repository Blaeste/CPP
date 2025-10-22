/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:15:39 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:25:30 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

// Default Constructor
Cure::Cure() : AMateria("cure") {

	//std::cout << "Cure Default Constructor called" << std::endl;
}

// String Constructor
Cure::Cure( std::string const &strVar ) : AMateria(strVar) {

	//std::cout << "Cure String Constructor called" << std::endl;
}

// Copy Constructor
Cure::Cure( const Cure &other ) : AMateria(other._type) {

	//std::cout << "Cure Copy Constructor called" << std::endl;
}

// Assignation operator
Cure &Cure::operator=(const Cure &other) {

	//std::cout << "Cure Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
Cure::~Cure() {

	//std::cout << "Cure Destructor called" << std::endl;
}

// Accessors

// Functions
AMateria *Cure::clone( void )const {

	return new Cure(*this);
}

void Cure::use( ICharacter &target ) const {

	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
