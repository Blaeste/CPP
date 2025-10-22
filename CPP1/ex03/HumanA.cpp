/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:29:20 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:15:18 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA( const std::string &name, Weapon &weapon ) :
	_name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

const std::string	&HumanA::getName( void ) const {

	return this->_name;
}

void	HumanA::setName( const std::string &name ) {

	this->_name = name;
}

void	HumanA::attack( void ) const {

	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}
