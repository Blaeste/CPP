/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:46:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/04 11:52:17 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testBureaucrateCreation( void ) {

	Bureaucrat lowGrade("Alice", 150);
	Bureaucrat midGrade("Bob", 80);
	Bureaucrat highGrade("Joe", 1);

	try {

		lowGrade.decrementGrade();

	} catch ( std::exception &e ) {

		std::cout << "Bureaucrat exception caught: " << e.what() << std::endl;
	}

}

void testShrubberyCreation( void ) {

	ShrubberyCreationForm shrub("Garden");

	Bureaucrat lowGrade("Alice", 150);
	Bureaucrat midGrade("Bob", 80);
	Bureaucrat highGrade("Joe", 1);

	try {

		lowGrade.signForm(shrub);
		midGrade.signForm(shrub);

		lowGrade.executeForm(shrub);
		highGrade.executeForm(shrub);

	} catch ( std::exception &e ) {

		std::cout << "Shrubbery exception caught: " << e.what() << std::endl;
	}
}

void testRobotomyRequest( void ) {

	RobotomyRequestForm robotomy("Robotomized");

	Bureaucrat lowGrade("Alice", 150);
	Bureaucrat midGrade("Bob", 45);
	Bureaucrat highGrade("Joe", 1);

	try {

		lowGrade.signForm(robotomy);
		midGrade.signForm(robotomy);
		highGrade.signForm(robotomy);

		lowGrade.executeForm(robotomy);
		midGrade.executeForm(robotomy);
		highGrade.executeForm(robotomy);

	} catch ( std::exception &e ) {

		std::cout << "Robotomy exception caught: " << e.what() << std::endl;
	}
}

void testPresidentialPardon( void ) {

	PresidentialPardonForm presidentialPardon("Pardon");


	Bureaucrat lowGrade("Alice", 150);
	Bureaucrat midGrade("Bob", 45);
	Bureaucrat highGrade("Joe", 1);

	try {

		lowGrade.signForm(presidentialPardon);
		midGrade.signForm(presidentialPardon);
		highGrade.signForm(presidentialPardon);

		lowGrade.executeForm(presidentialPardon);
		midGrade.executeForm(presidentialPardon);
		highGrade.executeForm(presidentialPardon);

	} catch ( std::exception &e ) {

		std::cout << "PresidentPardon exception caught: " << e.what() << std::endl;
	}
}

int main ( void ) {

	//testBureaucrateCreation();
	//testShrubberyCreation();
	//testRobotomyRequest();
	testPresidentialPardon();
}
