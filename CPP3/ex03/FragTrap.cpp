/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:11:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 13:19:13 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

// Default Constructor
FragTrap::FragTrap() : ClapTrap() {

		this->_hitPoints = 100;
		this->_energyPoints = 100;
		this->_attackDamage = 30;

		std::cout << "FragTrap Default Constructor called" << std::endl;
}

// String Constructor
FragTrap::FragTrap( std::string name ) : ClapTrap(name) {

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap String Constructor called" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {

	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

// Assignation operator
FragTrap &FragTrap::operator=(const FragTrap &other) {

	std::cout << "FragTrap Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap() {

	std::cout << "FragTrap Destructor called" << std::endl;
}

// Functions
void	FragTrap::highFivesGuys( void ) {

	std::cout << "FragTrap requests a positive high five! ✋" << std::endl;
}
