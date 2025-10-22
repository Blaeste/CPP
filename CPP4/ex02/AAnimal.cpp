/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:47:14 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:49:21 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

// Default Constructor
AAnimal::AAnimal() : _type("") {

	std::cout << "AAnimal Default Constructor called" << std::endl;
}

// String Constructor
AAnimal::AAnimal( std::string type ) : _type(type) {

	std::cout << "AAnimal String Constructor called" << std::endl;
}

// Copy Constructor
AAnimal::AAnimal( const AAnimal &other ) : _type(other._type) {

	std::cout << "AAnimal Copy Constructor called" << std::endl;
}

// Assignation operator
AAnimal &AAnimal::operator=(const AAnimal &other) {

	std::cout << "AAnimal Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
AAnimal::~AAnimal() {

	std::cout << "AAnimal Destructor called" << std::endl;
}

// Accessors
std::string	AAnimal::getType( void ) const {

	return this->_type;
}
