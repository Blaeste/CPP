/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:55:24 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 12:52:56 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {

	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();

		void	announce( void );
		void	setName( const std::string &value );
};

Zombie	*zombieHorde( int N, std::string name );
