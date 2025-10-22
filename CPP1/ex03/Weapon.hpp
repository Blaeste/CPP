/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:32:10 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/13 10:57:33 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {

	private:
		std::string	_type;

	public:
		explicit Weapon( const std::string &type );
		~Weapon();

		const std::string	&getType() const;
		void				setType( const std::string &type );
};
