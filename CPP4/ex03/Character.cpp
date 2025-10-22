/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:19:03 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:25:17 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

// Default Constructor
Character::Character() : _name("Unknown") {

	for ( int i = 0; i < 4; i++ ) {

		this->_inventory[i] = NULL;
	}
	for ( int i = 0; i < 10; i++ ) {

		this->_floor[i] = NULL;
	}
	//std::cout << "Character Default Constructor called" << std::endl;
}

// String Constructor
Character::Character( std::string const &name ) : _name(name) {

	for ( int i = 0; i < 4; i++ ) {

		this->_inventory[i] = NULL;
	}
	for ( int i = 0; i < 10; i++ ) {

		this->_floor[i] = NULL;
	}
	//std::cout << "Character String Constructor called" << std::endl;
}

// Copy Constructor
Character::Character( const Character &other ) : _name(other._name) {

	for ( int i = 0; i < 4; i++ ) {

		if ( other._inventory[i] ) {

			this->_inventory[i] =  other._inventory[i]->clone();
		} else {

			this->_inventory[i] = NULL;
		}
	}
	for ( int i = 0; i < 10; i++ ) {

		if ( other._floor[i] ) {

			this->_floor[i] =  other._floor[i]->clone();
		} else {

			this->_floor[i] = NULL;
		}
	}
	//std::cout << "Character Copy Constructor called" << std::endl;
}

// Assignation operator
Character &Character::operator=(const Character &other) {

	//std::cout << "Character Assignation operator called" << std::endl;
	if ( this != &other ) {

		for ( int i = 0; i < 4; i++ ) {

			delete this->_inventory[i];
			if ( other._inventory[i] ) {

				this->_inventory[i] =  other._inventory[i]->clone();
			} else {

				this->_inventory[i] = NULL;
			}
		}
		for ( int i = 0; i < 10; i++ ) {

			delete this->_floor[i];
			if ( other._floor[i] ) {

				this->_floor[i] =  other._floor[i]->clone();
			} else {

				this->_floor[i] = NULL;
			}
		}
		this->_name = other._name;
	}
	return *this;
}

// Destructor
Character::~Character() {

	for ( int i = 0; i < 4; i++ ) {

			delete this->_inventory[i];
	}
	for ( int i = 0; i < 10; i++ ) {

			delete this->_floor[i];
	}
	//std::cout << "Character Destructor called" << std::endl;
}

// Accessors
std::string const &Character::getName( void ) const {

	return this->_name;
}

// Functions Method
void Character::equip( AMateria *m ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( this->_inventory[i] == NULL ) {

			this->_inventory[i] = m;
			return ;
		}
	}

	std::cout << this->getName() << " has no space left in his inventory." << std::endl;
}

void Character::unequip( int idx) {

	if ( idx < 0 || idx >= 4 ) {

		std::cout << "This inventory slot doesn\'t exist, select between 0 and 3.";
		return ;
	}

	if ( this->_inventory[idx] == NULL ) {

		std::cout << this->getName() << " has nothing in this inventory slot." << std::endl;
	} else {

		for ( int i = 0; i < 10; i++ ) {

			if ( !this->_floor[i] ) {

				this->_floor[i] = this->_inventory[idx];
				break ;
			}
		}
		this->_inventory[idx] = NULL;
		std::cout << this->getName() << " has unequip his " << idx << " inventory slot." << std::endl;
	}
}

void Character::use(int idx, ICharacter &target ) {


	if ( idx < 0 || idx >= 4 ) {

		std::cout << "This inventory slot doesn\'t exist, select between 0 and 3.";
		return ;
	}

	if ( this->_inventory[idx] == NULL ) {

		std::cout << this->getName() << " has nothing in this inventory slot." << std::endl;
	} else {

		this->_inventory[idx]->use(target);
	}
}
