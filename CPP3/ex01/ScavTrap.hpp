/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:40:02 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 09:24:18 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		// Default Constructor
		ScavTrap();
		// String Constructor
		ScavTrap( std::string name );
		// Copy Constructor
		ScavTrap( const ScavTrap &other );
		// Assignation operator
		ScavTrap&operator=(const ScavTrap &other);
		// Destructor
		~ScavTrap();

		// Functions
		void	guardGate( void );
};
