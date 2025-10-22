/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:11:05 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 14:10:54 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {

	public:
		// Default Constructor
		FragTrap();
		// String Constructor
		FragTrap( std::string name );
		// Copy Constructor
		FragTrap( const FragTrap &other );
		// Assignation operator
		FragTrap&operator=(const FragTrap &other);
		// Destructor
		virtual ~FragTrap();

		// Functions
		void	highFivesGuys( void );

};
