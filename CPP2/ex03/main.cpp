/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:45:08 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/15 14:34:32 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void) {

	// Triangle simple
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);

	// Point à l'intérieur
	Point inside(0.2f, 0.2f);
	std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;  // doit afficher 1

	// Point à l'extérieur
	Point outside(1, 1);
	std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;  // doit afficher 0
}
