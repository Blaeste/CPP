/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:53:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:26:05 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

// Default Constructor
MateriaSource::MateriaSource() {

	for ( int i = 0; i < 4; i++ ) {

		_templates[i] = NULL;
	}

	//std::cout << "MateriaSource Default Constructor called" << std::endl;
}

// Copy Constructor
MateriaSource::MateriaSource( const MateriaSource &other ) {

	for ( int i = 0; i < 4; i++ ) {

		if (other._templates[i]) {

			this->_templates[i] = other._templates[i]->clone();
		} else {

			this->_templates[i] = NULL;
		}

	}
	//std::cout << "MateriaSource Copy Constructor called" << std::endl;
}

// Assignation operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {

	//std::cout << "MateriaSource Assignation operator called" << std::endl;
	if ( this != &other ) {

		for ( int i = 0; i < 4; i++ ) {

			delete this->_templates[i];

			if (other._templates[i]) {

				this->_templates[i] = other._templates[i]->clone();
			} else {

				this->_templates[i] = NULL;
			}
		}
	}
	return *this;
}

// Destructor
MateriaSource::~MateriaSource() {

	for ( int i = 0; i < 4; i++ ) {

		delete this->_templates[i];
	}
	//std::cout << "MateriaSource Destructor called" << std::endl;
}

// Accessors

// Functions
void MateriaSource::learnMateria( AMateria *materia ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( !this->_templates[i] ) {

			this->_templates[i] = materia;
			return ;
		}

	}

	std::cout << "Template list is full, nothing added" << std::endl;
}

AMateria *MateriaSource::createMateria( std::string const &type ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( this->_templates[i] && this->_templates[i]->getType() == type ) {

			return this->_templates[i]->clone();
		}

	}

	std::cout << "This type of materia ins\'t in the templates" << std::endl;
	return NULL;
}
