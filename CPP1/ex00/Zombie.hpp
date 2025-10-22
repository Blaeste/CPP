/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:55:24 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 12:46:58 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {

	private:
		std::string	_name;

	public:
		Zombie( const std::string &name );
		~Zombie( void );

		void	announce( void );
};

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
