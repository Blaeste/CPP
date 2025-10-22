/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:05:14 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 14:16:09 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap {

	private:
		std::string _name;

	public:
		// Default Constructor
		DiamondTrap();
		// String Constructor
		DiamondTrap( std::string name );
		// Copy Constructor
		DiamondTrap( const DiamondTrap &other );
		// Assignation operator
		DiamondTrap&operator=(const DiamondTrap &other);
		// Destructor
		virtual ~DiamondTrap();

		// Functions
		void	whoAmI();
};

