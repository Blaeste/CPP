/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:43 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 11:47:38 by eschwart         ###   ########.fr       */
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

	// Compare Op
	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	// Arithmetique Op
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	// In/Decrement Op
	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	// Min / Max functions
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

// Surcharge Op
std::ostream &operator<<(std::ostream &o, Fixed const &i);


