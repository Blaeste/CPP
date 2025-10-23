/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:30:43 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/23 09:34:45 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		// Default Constructor
		WrongCat( void );
		// String Constructor
		WrongCat( std::string const &type );
		// Copy Constructor
		WrongCat( const WrongCat &other );
		// Assignation operator
		WrongCat&operator=(const WrongCat &other);
		// Destructor
		~WrongCat( void );

		// Accessors


		// Functions

};

