/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:23:38 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 11:54:30 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ============================================================================
// Handlers

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Default Presidential Pardon", 25, 5),
	_target("Default") {
}

// Custom Constructor
PresidentialPardonForm::PresidentialPardonForm( std::string const &target ) :
	AForm("Presidential Pardon", 25, 5),
	_target(target) {
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) :
	AForm(other),
	_target(other._target) {
}

// Assignation operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {

	if ( this != &other )
		this->_target = other._target;
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// =============================================================================
// Getters

// =============================================================================
// Methods

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {

	if ( !this->getSigned() )
		throw FormNotSigned();

	if ( this->getExecGrade() < executor.getGrade() )
		throw GradeTooLowException();

	std::cout << "Informs that" << executor.getName()<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


// =============================================================================
// Operator overload
