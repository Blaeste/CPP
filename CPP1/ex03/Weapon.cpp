/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:28:59 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:14:30 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string &type ) : _type(type) {}

Weapon::~Weapon() {}

const std::string	&Weapon::getType( void ) const {

	return this->_type;
}

void	Weapon::setType( const std::string &type ) {

	this->_type = type;
}
