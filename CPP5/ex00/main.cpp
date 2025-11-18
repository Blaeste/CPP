/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:46:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/30 13:53:51 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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


int main ( void ) {

	testBureaucrateCreation();
}
