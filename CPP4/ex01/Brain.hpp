/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:44:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:09:52 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain {

	private:
		std::string _ideas[100];

	public:
		// Default Constructor
		Brain( void );
		// String Constructor
		Brain( std::string type );
		// Copy Constructor
		Brain( const Brain &other );
		// Assignation operator
		Brain&operator=(const Brain &other);
		// Destructor
		~Brain( void );

		// Accessors
		std::string	getIdea( int index ) const;

		// Functions

};
