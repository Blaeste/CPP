/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:38:01 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 14:29:45 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

// Default Constructor
ClapTrap::ClapTrap() :
	_name("no_name"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {

		std::cout << "ClapTrap Default Constructor called" << std::endl;
	}

// String Constructor
ClapTrap::ClapTrap( std::string name ) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {

		std::cout << "ClapTrap String Constructor called" << std::endl;
	}

// Copy Constructor
ClapTrap::ClapTrap( const ClapTrap &other ) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {

	std::cout << "ClapTrap Copy Constructor called" << std::endl;
}

// Assignation operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {

	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if ( this != &other ) {

		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {

	std::cout << "ClapTrap Destructor called" << std::endl;
}

// Accessors
unsigned int	ClapTrap::getHitPoints( void ) const {

	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {

	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {

	return _attackDamage;
}


// Functions
void	ClapTrap::attack( std::string const &target ) {

	if ( this->_hitPoints <= 0 ) {

		std::cout << "ClapTrap " << this->_name << " doesn\'t attack "
			<< target << ", it doesn\'t have enough hit point." << std::endl;
		return ;
	}
	if ( this->_energyPoints <= 0 ) {

		std::cout << "ClapTrap " << this->_name << " doesn\'t attack "
			<< target << ", it doesn\'t have enough energy point." << std::endl;
		return ;
	}

	this->_energyPoints--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!"
		<< std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	if ( amount > this->_hitPoints ) {

		this->_hitPoints = 0;
	} else {

		this->_hitPoints -= amount;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount
		<< " damage! HP: " << this->_hitPoints << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if ( this->_hitPoints <= 0 ) {

		std::cout << "ClapTrap " << this->_name
			<< " doesn\'t repair, it doesn\'t have enough hit point."
			<< std::endl;
		return ;
	}
	if ( this->_energyPoints <= 0 ) {

		std::cout << "ClapTrap " << this->_name
			<< " doesn\'t repair, it doesn\'t have enough energy point."
			<< std::endl;
		return ;
	}

	this->_energyPoints--;
	this->_hitPoints += amount;

	std::cout << "ClapTrap " << this->_name << " repairs itself for "
		<< amount << " hit points! HP: " << this->_hitPoints << std::endl;
}
