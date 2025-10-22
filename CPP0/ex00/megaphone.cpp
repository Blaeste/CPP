/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:07:05 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/09 10:56:02 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

#define STRING std::string

void	ft_megaphone( const STRING &str ) {

	std::locale loc;
	for ( STRING::size_type i = 0; i < str.length(); i++ )
		std::cout << std::toupper(str[i], loc);
}

int	main( int ac, char **av ) {

	if ( ac == 1 )
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for ( int i = 1; i < ac; i++ )
			ft_megaphone(av[i]);
	std::cout << std::endl;
}
