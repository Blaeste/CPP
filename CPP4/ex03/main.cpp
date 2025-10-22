/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:54:21 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/22 10:28:54 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>

int main ( void ) {

	std::cout << std::endl << "=== Test MateriaSource ===" << std::endl;

	// create source mat
	MateriaSource	*src = new MateriaSource();

	// Learn materia
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Create Character
	Character	*bob = new Character("Bob");

	// Create materia and equip
	AMateria	*tmp;

	tmp = src->createMateria("ice");
	bob->equip(tmp);

	tmp = src->createMateria("cure");
	bob->equip(tmp);

	// Create other test Character
	Character	*bib = new Character("Bib");

	std::cout << std::endl << "--- Use Materia ---" << std::endl;
	// Use materia
	bob->use(0, *bib);
	bob->use(1, *bib);

	std::cout << std::endl << "--- Unasigned Materia ---" << std::endl;
	// Test unasigned
	tmp = src->createMateria("fire");
	if ( !tmp ) {

		std::cout << "Fire Materia not found" << std::endl;
	}

	std::cout << std::endl << "--- Unequiped Materia ---" << std::endl;
	// Test unequip
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);

	bob->unequip(0);
	bob->use(0, *bib);
	bob->use(1, *bib);

	std::cout<< std::endl;

	// Clear
	delete bib;
	delete bob;
	delete src;
}

// int main () {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }
