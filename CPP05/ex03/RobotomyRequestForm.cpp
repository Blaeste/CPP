/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:24:57 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/03 10:49:42 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Includes for rdm
#include <cstdlib>
#include <ctime>

// ============================================================================
// Handlers

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Default Robotomy Request", 72, 45),
	_target("Default") {
}

// Custom Constructor
RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) :
	AForm("Robotomy Request", 72, 45),
	_target(target) {
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) :
	AForm(other),
	_target(other._target) {
}

// Assignation operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {

	if ( this != &other )
		this->_target = other._target;
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// =============================================================================
// Getters

// =============================================================================
// Methods

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {

	if ( !this->getSigned() )
		throw FormNotSigned();

	if ( this->getExecGrade() < executor.getGrade() )
		throw GradeTooLowException();

	std::cout << "** Some drilling noises **" << std::endl;

	std::srand(std::time(0));

	if ( std::rand() % 2 )
		std::cout << executor.getName() << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}


// =============================================================================
// Operator overload
