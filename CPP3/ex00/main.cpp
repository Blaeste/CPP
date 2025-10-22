/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 14:03:00 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int main(void) {

	ClapTrap basic("Basic");

	std::cout << std::endl;

	// Attack
	std::cout << "=== ATTACK ==" << std::endl;
	basic.attack("Enemy");

	std::cout << std::endl;

	// Take dmg
	std::cout << "=== DEFENCE ==" << std::endl;
	basic.takeDamage(5);

	std::cout << std::endl;

	// Stamina test
	std::cout << "=== STAM TEST ==" << std::endl;
	for ( int i = 0; i <= 10; i++ ) {

		basic.attack("Air");
	}

	std::cout << std::endl;
}
