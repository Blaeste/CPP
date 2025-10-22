/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:29:42 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:14:41 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB( const std::string &name ) :
	_name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

const std::string	&HumanB::getName( void ) const {

	return this->_name;
}

void	HumanB::setName( const std::string &name ) {

	this->_name = name;
}

void	HumanB::setWeapon( Weapon &weapon ) {

	this->_weapon = &weapon;
}

void	HumanB::unsetWeapon() {

	this->_weapon = NULL;
}

void	HumanB::attack( void ) const {

	if ( this->_weapon )
		std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon" << std::endl;
}
