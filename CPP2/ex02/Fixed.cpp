/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:16 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 12:27:08 by eschwart         ###   ########.fr       */
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

	this->_rawBits += (1 << this->_fractBits); // + 256
	return *this;
}

Fixed	Fixed::operator++(int) {

	Fixed	old_val = *this;
	this->_rawBits += (1 << this->_fractBits); // + 256
	return old_val;
}

Fixed	&Fixed::operator--() {

	this->_rawBits -= (1 << this->_fractBits); // - 256
	return *this;
}

Fixed	Fixed::operator--(int) {

	Fixed	old_val =  *this;
	this->_rawBits -= ( 1 << this->_fractBits);  // - 256;
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
