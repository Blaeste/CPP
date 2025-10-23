/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:30:45 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 09:38:10 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

// Default Constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat") {

	std::cout << "WrongCat Default Constructor called" << std::endl;
}

// String Constructor
WrongCat::WrongCat( std::string const &strVar ) : WrongAnimal(strVar) {

	std::cout << "WrongCat String Constructor called" << std::endl;
}

// Copy Constructor
WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other) {

	std::cout << "WrongCat Copy Constructor called" << std::endl;
}

// Assignation operator
WrongCat &WrongCat::operator=(const WrongCat &other) {

	std::cout << "WrongCat Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
WrongCat::~WrongCat() {

	std::cout << "WrongCat Destructor called" << std::endl;
}

// Accessors

// Functions
