/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:16 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 11:33:20 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &src ) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( const int n ) {

	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << this->_fractBits;
}

Fixed::Fixed( const float f ) {

	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(f * 256);
}


Fixed	&Fixed::operator=( const Fixed &rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs ) {

		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


// Accessors
int	Fixed::getRawBits( void ) const {

	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {

	this->_rawBits = raw;
}

// Functions
float	Fixed::toFloat( void ) const {

	return this->_rawBits / 256.0f;
}

int		Fixed::toInt( void ) const {

	return this->_rawBits >> this->_fractBits;
}

// Operator
std::ostream &operator<<(std::ostream &o, Fixed const &i) {

	o << i.toFloat();
	return o;
}
