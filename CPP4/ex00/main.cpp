/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/16 15:37:13 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {

	// Test sujet

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();

	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;

	// Test 1 : obj
	Cat	cat;
	Dog	dog;

	std::cout << std::endl;

	std::cout << "=== TEST 1: OBJ ===" <<std::endl;
	std::cout << "cat: ";
	cat.makeSound();
	std::cout << "dog: ";
	dog.makeSound();

	std::cout << std::endl;

	// Test 2 : ptr class
	Animal	*animal1 = new Cat();
	Animal	*animal2 = new Dog();

	std::cout << std::endl;

	std::cout << "=== TEST 1: PTR CLASS ===" <<std::endl;

	std::cout << "animal1: ";
	animal1->makeSound();
	std::cout << "animal2: ";
	animal2->makeSound();

	std::cout << std::endl;

	delete animal1;
	delete animal2;

	std::cout << std::endl;

	// Test 3 : tab animaux
	Animal	*animals[4] = {
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog()
	};

	std::cout << std::endl;

	std::cout << "=== TEST 1: TAB ===" <<std::endl;

	for ( int i = 0; i < 4; i++ ) {

		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		delete animals[i];
	}

	std::cout << std::endl;
}
