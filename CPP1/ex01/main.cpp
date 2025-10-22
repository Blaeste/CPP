/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:18:01 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 10:31:30 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main ( void ) {

	int N = 10;

	Zombie	*h = zombieHorde(N, "Clovis");
	if ( !h ) return 1;

	for ( int i = 0; i < N; i++ )
		h[i].announce();

	delete [] h;
}
