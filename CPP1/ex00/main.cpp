/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:07:05 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 10:12:51 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {

	// Heap
	Zombie	*z = newZombie("Foo");
	z->announce();

	delete z;
	// Stack
	randomChump("Bar");
}
