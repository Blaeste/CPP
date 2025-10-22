/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:35:01 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 14:46:50 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

// Default Constructor
Point::Point() : _x(0), _y(0) {}

// Float Constructor
Point::Point( const float x, const float y) : _x(x), _y(y) {}

// Copy Constructor
Point::Point( const Point &src ) : _x(src._x), _y(src._y) {}

// Copy Assignment Operator
Point	&Point::operator=( const Point &rhs ) {

	(void)rhs;
	return *this;
}

// Destructor
Point::~Point() {}

// Accessors
Fixed	Point::getX( void ) const {

	return this->_x;
}

Fixed	Point::getY( void ) const {

	return this->_y;
}

