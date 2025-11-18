/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:12:23 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 13:14:16 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// ============================================================================
// Handlers

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Default Shrubbery Creation", 145, 137),
	_target("Default") {
}

// Custom Constructor
ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) :
	AForm("Shrubbery Creation", 145, 137),
	_target(target) {
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) :
	AForm(other),
	 _target(other._target) {
}

// Assignation operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {

	if ( this != &other )
		this->_target = other._target;
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// =============================================================================
// Getters

// =============================================================================
// Methods

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {

	if ( !this->getSigned() )
		throw FormNotSigned();

	if ( this->getExecGrade() < executor.getGrade() )
		throw GradeTooLowException();

	std::string filename = this->_target + "_shrubbery";

	std::ofstream file(filename.c_str()); // -std=c++98
	if ( !file.is_open() )
		throw ShrubberyFileCreation();

	file << "    /\\    " << std::endl;
	file << "   /  \\   " << std::endl;
	file << "  /    \\  " << std::endl;
	file << "   /  \\   " << std::endl;
	file << "  /____\\  " << std::endl;
	file << "    ||     " << std::endl;

	std::cout << executor.getName() << " execute " << this->getName() << std::endl;

	file.close();
}

// =============================================================================
// Operator overload
