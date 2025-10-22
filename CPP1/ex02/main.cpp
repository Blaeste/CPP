/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:14:22 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 10:33:19 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main ( void ) {

	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "Adress of brain: " << &brain << std::endl;
	std::cout << "Adress in stringPTR: " << stringPTR << std::endl;
	std::cout << "Adress in stringREF: " << &stringREF << std::endl;

	std::cout << "Value of brain: " << brain << std::endl;
	std::cout << "Value via stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value via stringREF: " << stringREF << std::endl;
}
