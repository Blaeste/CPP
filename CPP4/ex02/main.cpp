/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/17 11:51:47 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void) {

	//AAnimal aanimal; // does not compile -> absctract class (pure virtual function makesound())

	// Test : brain idea
	std::cout << std::endl << "--- Cat original ---" << std::endl << std::endl;

	Cat cat4;
	Dog dog1;

	std::cout << std::endl << "Cat4 idea 0: " << cat4.getBrainIdea(0) << std::endl;
	std::cout << "Cat4 idea 1: " << cat4.getBrainIdea(1) << std::endl;
	std::cout << "Dog1 idea 0: " << dog1.getBrainIdea(0) << std::endl;
	std::cout << "Dog1 idea 1: " << dog1.getBrainIdea(1) << std::endl;

	std::cout << std::endl << "--- Copy Constructor ---" << std::endl << std::endl;

	Cat cat5 = cat4;
	Dog dog2 = dog1;

	std::cout << std::endl << "Cat5 idea 0: " << cat5.getBrainIdea(0) << std::endl;
	std::cout << "Cat5 idea 1: " << cat5.getBrainIdea(1) << std::endl;
	std::cout << "Dog2 idea 0: " << dog2.getBrainIdea(0) << std::endl;
	std::cout << "Dog2 idea 1: " << dog2.getBrainIdea(1) << std::endl;

	std::cout << std::endl << "--- Assignement Operator ---" << std::endl << std::endl;

	Cat cat6;
	Dog dog3;
	cat6 = cat4;
	dog3 = dog1;

	std::cout << std::endl << "Cat6 idea 0: " << cat6.getBrainIdea(0) << std::endl;
	std::cout << "Cat6 idea 1: " << cat6.getBrainIdea(1) << std::endl;
	std::cout << "Dog3 idea 0: " << dog3.getBrainIdea(0) << std::endl;
	std::cout << "Dog3 idea 1: " << dog3.getBrainIdea(1) << std::endl;

	std::cout << std::endl << "--- indep brain ? ---" << std::endl << std::endl;

	std::cout << "Same idea 0 ? " << (cat4.getBrainIdea(0) == cat5.getBrainIdea(0) ? "YES" : "NO") << std::endl;
	std::cout << "Same brain adress ? " << (&cat4 == &cat5 ? "YES (Problem)" : "NO (ok)") << std::endl;

	// Test : Check brain indep
	std::cout << std::endl << "--- Segmented Destruction---" << std::endl << std::endl;
}
