/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:54:40 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:40:52 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

const std::string	Harl::DEBUG_M =
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
const std::string	Harl::INFO_M =
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
const std::string	Harl::WARNING_M =
	"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
const std::string	Harl::ERROR_M =
	"This is unacceptable! I want to speak to the manager now.";

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug( void ) {

	std::cout << DEBUG_M << std::endl;
}

void	Harl::info( void ) {

	std::cout << INFO_M << std::endl;
}

void	Harl::warning( void ) {

	std::cout << WARNING_M << std::endl;
}

void	Harl::error( void ) {

	std::cout << ERROR_M << std::endl;
}

void	Harl::complain( std::string level )
{
	const std::string	keys[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*functions[4])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for ( int i = 0; i < 4; i++ ) {

		if ( level == keys[i] ) {

			(this->*functions[i])();
			return ;
		}
	}

	std::cout << "Probably bullshiting an other guys (error)" << std::endl;
}
