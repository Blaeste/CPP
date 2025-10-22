/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:54:31 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:35:52 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

// Default Constructor
Cat::Cat() : Animal("Cat") {

	std::cout << "Cat Default Constructor called" << std::endl;
}

// String Constructor
Cat::Cat( std::string type ) : Animal(type) {

	std::cout << "Cat String Constructor called" << std::endl;
}

// Copy Constructor
Cat::Cat( const Cat &other ) : Animal(other._type) {

	std::cout << "Cat Copy Constructor called" << std::endl;
}

// Assignation operator
Cat &Cat::operator=(const Cat &other) {

	std::cout << "Cat Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_type = other._type;
	}
	return *this;
}

// Destructor
Cat::~Cat() {

	std::cout << "Cat Destructor called" << std::endl;
}

// Functions
void	Cat::makeSound( void ) const {

	std::cout << "Meow!" << std::endl;
}
