/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:43 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/14 13:45:14 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {

private:
	static const int	_fractBits = 8;
	int					_rawBits;

public:
	Fixed();
	Fixed( const Fixed &src );
	Fixed &operator=(const Fixed &);
	~Fixed();

	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );
};
