/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:34:58 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 14:34:01 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {

private:
	const Fixed	_x;
	const Fixed	_y;

public:
	Point();
	Point( const float x, const float y );
	Point( const Point &src );
	Point &operator=(const Point &rhs);
	~Point();

	// Accessors
	Fixed	getX( void ) const;
	Fixed	getY( void ) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
