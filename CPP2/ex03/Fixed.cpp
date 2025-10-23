/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:16 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 09:23:29 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default Constructor
Fixed::Fixed() : _rawBits(0) {}

// Copy Constructor
Fixed::Fixed( const Fixed &src ) {

	*this = src;
}

// Int Constructor
Fixed::Fixed( const int n ) {

	this->_rawBits = n << this->_fractBits;
}

// Float Constructor
Fixed::Fixed( const float f ) {

	this->_rawBits = roundf(f * 256);
}

// Copy Assignment Operator
Fixed	&Fixed::operator=( const Fixed &rhs ) {

	if ( this != &rhs ) {

		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {}


// Accessors
int	Fixed::getRawBits( void ) const {

	return this->_rawBits;
}

void	Fixed::setRawBits( int const raw ) {

	this->_rawBits = raw;
}

// Conversions
float	Fixed::toFloat( void ) const {

	return this->_rawBits / 256.0f;
}

int		Fixed::toInt( void ) const {

	return this->_rawBits >> this->_fractBits;
}

// Compare Op
bool	Fixed::operator>(const Fixed &rhs) const{

	return this->_rawBits > rhs._rawBits;
}

bool	Fixed::operator<(const Fixed &rhs) const {

	return this->_rawBits < rhs._rawBits;
}

bool	Fixed::operator>=(const Fixed &rhs) const {

	return this->_rawBits >= rhs._rawBits;
}

bool	Fixed::operator<=(const Fixed &rhs) const {

	return this->_rawBits <= rhs._rawBits;
}

bool	Fixed::operator==(const Fixed &rhs) const {

	return this->_rawBits == rhs._rawBits;
}

bool	Fixed::operator!=(const Fixed &rhs) const{

	return this->_rawBits != rhs._rawBits;
}

// Arithmetique Op
Fixed	Fixed::operator+(const Fixed &rhs) const {

	Fixed result;
	result.setRawBits(this->_rawBits + rhs._rawBits);
	return result;
}

Fixed	Fixed::operator-(const Fixed &rhs) const {

	Fixed result;
	result.setRawBits(this->_rawBits - rhs._rawBits);
	return result;
}

Fixed	Fixed::operator*(const Fixed &rhs) const {

	Fixed result;
	result.setRawBits((this->_rawBits * rhs._rawBits) >> this->_fractBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &rhs) const {

	Fixed result;
	result.setRawBits((this->_rawBits << this->_fractBits) / rhs._rawBits);
	return result;
}

// In/Decrement Op
Fixed	&Fixed::operator++() {

	this->_rawBits += 1 ; // inc raw bit pas nb original (1 << this->_fractBits); // + 256
	return *this;
}

Fixed	Fixed::operator++(int) {

	Fixed	old_val = *this;
	this->_rawBits += 1; // inc raw bit pas nb original (1 << this->_fractBits); // + 256
	return old_val;
}

Fixed	&Fixed::operator--() {

	this->_rawBits -= 1; // decr raw bit pas nb original(1 << this->_fractBits); // - 256
	return *this;
}

Fixed	Fixed::operator--(int) {

	Fixed	old_val =  *this;
	this->_rawBits -= 1; // derc raw bit pas nb original( 1 << this->_fractBits);  // - 256;
	return old_val;
}

// Min / Max functions
Fixed		&Fixed::min(Fixed &a, Fixed &b) {

	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {

	if (a < b)
		return a;
	return b;
}

Fixed		&Fixed::max(Fixed &a, Fixed &b) {

	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {

	if (a > b)
		return a;
	return b;
}


// Sur Operator (cout << Fixed)
std::ostream &operator<<(std::ostream &o, Fixed const &i) {

	o << i.toFloat();
	return o;
}
