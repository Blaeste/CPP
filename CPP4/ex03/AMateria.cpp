/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:17:27 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:24:45 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

// Default Constructor
AMateria::AMateria() : _type("Default") {

	//std::cout << "AMateria Default Constructor called" << std::endl;
}

// String Constructor
AMateria::AMateria( std::string const &type ) : _type(type) {

	//std::cout << "AMateria String Constructor called" << std::endl;
}

// Copy Constructor
AMateria::AMateria( const AMateria &other ) : _type(other._type) {

	//std::cout << "AMateria Copy Constructor called" << std::endl;
}

// Assignation operator
AMateria &AMateria::operator=(const AMateria &other) {

	//std::cout << "AMateria Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
AMateria::~AMateria() {

	//std::cout << "AMateria Destructor called" << std::endl;
}

// Accessors
std::string	const &AMateria::getType( void ) const {

	return this->_type;
}
