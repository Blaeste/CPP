/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:28:27 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:17:43 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	ft_replace_all( const std::string &str, const std::string &s1,
		const std::string &s2) {

	if ( s1.empty() ) return str;

	std::string	rslt;
	size_t	pos = 0;
	size_t	found;

	while ( (found = str.find(s1, pos)) != std::string::npos ) {

		rslt.append(str, pos, found - pos);
		rslt.append(s2);
		pos = found + s1.length();
	}
	rslt.append(str, pos, str.length() - pos);
	return rslt;
}

int main(int ac, char **av) {

	if ( ac != 4 ) {

		std::cout << "Usage: " << av[0] << " <fichier> <s1> <s2>" << std::endl;
		return 1;
	}

	std::ifstream infile(av[1]); // error si utiliser avec STRING

	if ( !infile.is_open() ) {

		std::cout << "Error opening the infile" << std::endl;
		return 1;
	}

	std::string	outname = std::string(av[1]) + ".replace"; // prep for ostream (.c_str)
	std::ofstream outfile(outname.c_str());

	if ( !outfile.is_open() ) {

		std::cout << "Error creating the outfile" << std::endl;
		return 1;
	}

	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::string line;

	while ( std::getline(infile, line) )
		outfile << ft_replace_all(line, s1, s2) << std::endl;

	infile.close();
	outfile.close();
}
