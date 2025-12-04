/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:46:35 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/24 10:47:58 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"


int main( int ac, char **av ) {

	if ( ac != 2 ) return 1;

	try {

		BitcoinExchange btc("data.csv");
		btc.processFile(av[1]);

	}

	catch (const std::exception &e) {

		std::cout << e.what() << std::endl;
	}

	return 0;
}
