/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 14:01:29 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main(void) {

	ClapTrap basic("Basic");
	ScavTrap guard("Guard");
	FragTrap frag("Frag");

	std::cout << std::endl;

	// Attack
	std::cout << "=== ATTACK ==" << std::endl;
	basic.attack("Enemy");
	guard.attack("Enemy");
	frag.attack("Enemy");

	std::cout << std::endl;

	// Take dmg
	std::cout << "=== DEFENCE ==" << std::endl;
	basic.takeDamage(5);
	guard.takeDamage(50);
	frag.takeDamage(60);

	std::cout << std::endl;

	// Special
	std::cout << "=== SPECIAL ==" << std::endl;
	guard.guardGate();
	frag.highFivesGuys();

	std::cout << std::endl;

	// Stamina test
	std::cout << "=== STAM TEST ==" << std::endl;
	for ( int i = 0; i <= 10; i++ ) {

		frag.attack("Air");
	}

	std::cout << std::endl;
}
