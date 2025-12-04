/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:59:15 by eschwart          #+#    #+#             */
/*   Updated: 2025/12/04 10:01:49 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main ( int ac, char **av) {

	if ( ac != 2 )
	{
		std::cout << "Usage: " << av[0] << " <\"0 2 + 5 * 2 - 6 +\">\n";
		return 1;
	}

	try {

		RPN rpc(av[1]);

	}

	catch (const std::exception &e) {

		std::cout << e.what() << std::endl;
	}


	return 0;
}
