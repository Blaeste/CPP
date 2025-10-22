/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:54:21 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:44:47 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main( int ac, char **av ) {

	if ( ac != 2 ) {

		std::cout << "Usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}

	Harl harl;

	std::string input_level = av[1];
	int	current_level = -1;

	std::string levels_name[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++ ) {

		if ( input_level == levels_name[i] ) {

			current_level = i;
			break ;
		}
	}

	switch ( current_level ) {

	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");
		std::cout << std::endl;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		break ;
	default:
		std::cout << "Probably bullshiting an other guys (error)" << std::endl;
	}
}
