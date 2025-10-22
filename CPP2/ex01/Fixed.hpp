/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:43 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 10:33:15 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {

private:
	static const int	_fractBits = 8;
	int					_rawBits;

public:
	Fixed();
	Fixed( const Fixed &src );

	Fixed( const int n );
	Fixed( const float f );

	Fixed &operator=(const Fixed &);
	~Fixed();

	// Accessors
	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );

	// Functions
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

// Surcharge Op
std::ostream &operator<<(std::ostream &o, Fixed const &i);
