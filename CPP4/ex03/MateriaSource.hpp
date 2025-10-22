/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:53:44 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:22:31 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:
		AMateria	*_templates[4];

	public:
		// Default Constructor
		MateriaSource( void );
		// Copy Constructor
		MateriaSource( const MateriaSource &other );
		// Assignation operator
		MateriaSource&operator=(const MateriaSource &other);
		// Destructor
		virtual ~MateriaSource( void );

		// Accessors


		// Functions
		virtual void learnMateria( AMateria *materia );
		virtual AMateria *createMateria( std::string const &type );

};
