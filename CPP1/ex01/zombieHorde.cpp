/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:18:26 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 13:03:38 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name ) {

	if ( N <= 0 )
		return 0;

	Zombie	*horde = new(std::nothrow) Zombie[N];
	if ( !horde )
		return 0;

	for ( int i = 0; i < N; i++ )
		horde[i].setName(name);

	return horde;
}
