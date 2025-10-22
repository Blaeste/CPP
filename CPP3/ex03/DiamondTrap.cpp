/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:05:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/21 09:39:48 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

// Default Constructor
DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {

	ScavTrap	tempScav;
	FragTrap	tempFrag;

	this->_hitPoints = tempFrag.getHitPoints();
	this->_energyPoints = tempScav.getEnergyPoints();
	this->_attackDamage = tempFrag.getAttackDamage();

	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

// String Constructor
DiamondTrap::DiamondTrap( std::string name ) : ScavTrap(name), FragTrap(name) {

	ScavTrap	tempScav;
	FragTrap	tempFrag;

	this->_name = name;
	ClapTrap::_name = name + "_clap_name";

	this->_hitPoints = tempFrag.getHitPoints();
	this->_energyPoints = tempScav.getEnergyPoints();
	this->_attackDamage = tempFrag.getAttackDamage();

	std::cout << "DiamondTrap String Constructor called" << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ScavTrap(other), FragTrap(other) {

	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

// Assignation operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {

	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {

	std::cout << "DiamondTrap Destructor called" << std::endl;
}

// Functions
void	DiamondTrap::whoAmI( void ) {

	std::cout << "I am " << this->_name << " and my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
}
