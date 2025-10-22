/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:32:21 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:10:46 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

// Forward Declaration
class Weapon;

class HumanA {

	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA( const std::string &name, Weapon &weapon );
		~HumanA();

		void 				attack() const;
		const std::string	&getName( void ) const;
		void 				setName( const std::string &name );
};
