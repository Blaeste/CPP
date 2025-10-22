/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:18:06 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 14:31:37 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	calcOrientedArea( Point p1, Point p2, Point p3)
{
	Fixed	area =
				(p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) -
				(p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed	area1 = calcOrientedArea(point, a, b);
	Fixed	area2 = calcOrientedArea(point, b, c);
	Fixed	area3 = calcOrientedArea(point, c, a);

	bool allPositive = (area1 > 0) && (area2 > 0) && (area3 > 0);
	bool allNegative = (area1 < 0) && (area2 < 0) && (area3 < 0);

	return allPositive || allNegative;
}
