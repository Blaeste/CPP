/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:38:07 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 11:41:22 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap {

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Default Constructor
		ClapTrap();
		// String Constructor
		ClapTrap( std::string name );
		// Copy Constructor
		ClapTrap( const ClapTrap &other );
		// Assignation operator
		ClapTrap&operator=(const ClapTrap &other);
		// Destructor
		virtual ~ClapTrap();

		// Accessors

		// Functions
		void	attack( std::string const &target );
		void 	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );


};
