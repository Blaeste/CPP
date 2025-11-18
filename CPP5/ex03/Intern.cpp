/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:16:15 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/05 13:55:26 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// ============================================================================
// Handlers

// Default Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern( const Intern &other ) {
	(void)other;
}

// Assignation operator
Intern &Intern::operator=(const Intern &other) {

	(void)other;
	return *this;
}

// Destructor
Intern::~Intern() {}

// =============================================================================
// Getters

// =============================================================================
// Methods

enum formType { SHRUBBERY = 0, ROBOTOMY = 1, PRESIDENTIAL = 2, UNKNOW = -1 };

int getFormType( std::string formName ) {
	if ( formName == "shrubbery creation" ) return SHRUBBERY;
	if ( formName == "robotomy request" ) return ROBOTOMY;
	if ( formName == "presidential pardon" ) return PRESIDENTIAL;
	return UNKNOW;
}

AForm *Intern::makeForm( std::string formName, std::string formTarget ) {

	switch ( getFormType(formName) ) {

	case SHRUBBERY:
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(formTarget);
	case ROBOTOMY:
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(formTarget);
	case PRESIDENTIAL:
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(formTarget);
	default:
		std::cout << "Unknown form: " << formName << std::endl;
		return NULL;
	}
}

// =============================================================================
// Operator overload
