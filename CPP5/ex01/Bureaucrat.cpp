/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:49:53 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/30 12:34:26 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// =============================================================================
// Handlers

// Default Constructor
Bureaucrat::Bureaucrat() : _name("Random Dude"), _grade(150) {}

// String Constructor
Bureaucrat::Bureaucrat( std::string const &name, int grade ) : _name(name), _grade(grade) {

	if ( this->_grade < 1 )
			throw GradeTooHighException();

	if ( this->_grade > 150 )
			throw GradeTooLowException();

	if ( this->_name.empty() )
		throw BureaucratNameEmpty();
}

// Copy Constructor
Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name), _grade(other._grade) {}

// Assignation operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {

	if ( this != &other )
		this->_grade = other._grade;

	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// =============================================================================
// Getters

const std::string	Bureaucrat::getName( void ) const {

	return this->_name;
}

unsigned int Bureaucrat::getGrade( void ) const {

	return this->_grade;
}

// =============================================================================
// Methods

void Bureaucrat::incrementGrade( void ) {

	if ( this->_grade == 1 )
		throw GradeTooHighException();

	else {
		std::cout << "Incrementing " << this->_name << " grade." << std::endl;
		this->_grade--;
	}
}

void Bureaucrat::decrementGrade( void ) {

	if ( this->_grade == 150 )
		throw GradeTooLowException();

	else {

		std::cout << "Decrementing " << this->_name << " grade." << std::endl;
		this->_grade++;
	}
}

void Bureaucrat::signForm( Form &form ) {

	try {

		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;

	} catch ( std::exception &e ) {

		std::cout << this->_name << " couldn\'t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// =============================================================================
// overload op

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
