/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:36:50 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/30 13:45:44 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// =============================================================================
// Handlers

// Default Constructor
Form::Form() :
	_name("Default Form"),
	_signed(false),
	_signGrade(150),
	_execGrade(150)  {
}

// Custom Constructor
Form::Form( std::string const &name, unsigned int signGrade, unsigned int execGrade ) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {

	if ( this->_signGrade < 1 || this->_signGrade > 150 || this->_execGrade < 1 || this->_execGrade > 150 ) {
		if ( this->_signGrade < 1 || this->_execGrade < 1 )
			throw GradeTooHighException();
		else
			throw GradeTooLowException();
	}

	if ( this->_name.empty() )
		throw FormNameEmpty();
}

// Copy Constructor
Form::Form( const Form &other ) :
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade) {
}

// Assignation operator
Form &Form::operator=(const Form &other) {

	if ( this != &other )
		this->_signed = other._signed;
	return *this;
}

// Destructor
Form::~Form() {}

// =============================================================================
// Getters

std::string Form::getName( void ) const {

	return this->_name;
}

bool Form::getSigned( void ) const {

	return this->_signed;
}

unsigned int Form::getSignGrade( void ) const {

	return this->_signGrade;
}

unsigned int Form::getExecGrade( void ) const {

	return this->_execGrade;
}

// =============================================================================
// Methods

void Form::beSigned( Bureaucrat b ) {

	if ( this->_signed )
		throw FormAlreadySigned();

	if ( this->_signGrade < b.getGrade() )
		throw GradeTooLowException();
	else
		this->_signed = true;
}

// =============================================================================
// Operator overload

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << std::endl << "Form: " << form.getName() << ", signed: " << form.getSigned()
		<< ", sign Grade min: " << form.getSignGrade() << ", exec Grade min: "
		<< form.getExecGrade() << std::endl;
	return os;
}
