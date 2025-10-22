/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:32:31 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 11:10:43 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

// Forward Declaration
class Weapon;

class HumanB {

	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		explicit HumanB( const std::string &name );
		~HumanB();

		void				setWeapon( Weapon &weapon );
		void				unsetWeapon( void );
		void				attack() const;
		const std::string	&getName( void ) const;
		void 				setName( const std::string &name );
};
