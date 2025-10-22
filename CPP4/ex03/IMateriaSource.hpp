/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:49:11 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/20 09:52:18 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

class IMateriaSource {

	public:
		virtual	~IMateriaSource() {}
		virtual void learnMateria( AMateria *) = 0;
		virtual AMateria *createMateria( std::string const &type ) = 0;
};
