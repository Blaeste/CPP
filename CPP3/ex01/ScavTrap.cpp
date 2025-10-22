/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:39:57 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 13:06:31 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap() {

		this->_hitPoints = 100;
		this->_energyPoints = 50;
		this->_attackDamage = 20;

		std::cout << "ScavTrap Default Constructor called" << std::endl;
}

// String Constructor
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap String Constructor called" << std::endl;
}

// Copy Constructor
ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {

	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

// Assignation operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {

	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {

	std::cout << "ScavTrap Destructor called" << std::endl;
}

// Functions
void	ScavTrap::guardGate( void ) {

	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
