/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:59:15 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/26 11:17:28 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	try
	{
		PmergeMe pm(ac, av);

		pm.displayResults();
	}

	catch (const std::exception &e)
	{

		std::cout << e.what() << std::endl;
	}

	return 0;
}
