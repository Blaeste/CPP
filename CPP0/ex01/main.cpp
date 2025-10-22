/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:07:05 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/10 10:13:28 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook	phoneBook;

void	ft_hangle_gnl() {

	std::cout << "EOF detected." << std::endl;
	exit(EXIT_SUCCESS);
}

STRING	ft_manage_input(const STRING &prompt) {

	STRING	input;

	while ( input.empty() ) {
		std::cout << prompt << " : ";
		if ( !std::getline(std::cin, input) ) {
			ft_hangle_gnl();
		}
		if ( input.empty() )
			std::cout << prompt << " cannot be empty" << std::endl;
		if ( prompt == "Phone Number") {
			if( input.find_first_not_of("0123456789 ") == std::string::npos )
				return (input);
			std::cout << "Phone number must be only digits" << std::endl;
			input.clear();
		}
	}
	return (input);
}

void	ft_add_contact() {

	Contact	newContact;
	STRING	input;

	input = ft_manage_input("First Name");
	newContact.setField(FIRST_NAME, input);
	input = ft_manage_input("Last Name");
	newContact.setField(LAST_NAME, input);
	input = ft_manage_input("Nickname");
	newContact.setField(NICKNAME, input);
	input = ft_manage_input("Phone Number");
	newContact.setField(PHONE_NUMBER, input);
	input = ft_manage_input("Darkest secret");
	newContact.setField(DARKEST_SECRET, input);

	phoneBook.addContact(newContact);
	std::cout << "Contact added sucessfully." << std::endl;
}

void	ft_search_contact() {
	STRING	input;
	int		index;
	Contact contact;

	if ( phoneBook.getTotalContacts() == 0 ) {
		std::cout << "No contacts available." << std::endl;
		return ;
	}

	phoneBook.displayContacts();

	std::cout << "Enter contact index: ";
	std::getline(std::cin, input);
	if ( input.find_first_not_of("01234567") != std::string::npos || input.empty() ) {
		std::cout << "Invalid Index." << std::endl;
		return ;
	}

	try {
		index = std::atoi(input.c_str());
		contact = phoneBook.getContact(index);

		std::cout << "First Name: " << contact.getField(FIRST_NAME) << std::endl;
		std::cout << "Last Name: " << contact.getField(LAST_NAME) << std::endl;
		std::cout << "Nickname: " << contact.getField(NICKNAME) << std::endl;
		std::cout << "Phone Number: " << contact.getField(PHONE_NUMBER) << std::endl;
		std::cout << "Darkest Secret: " << contact.getField(DARKEST_SECRET) << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main( void ) {

	STRING		input;

	while ( true ) {

		std::cout << "Please entrer a cmd : ";
		if ( !std::getline(std::cin, input) )
			ft_hangle_gnl();

		if ( input == "EXIT" )
			break ;
		else if ( input == "ADD" )
			ft_add_contact();
		else if ( input == "SEARCH" )
			ft_search_contact();
		else
			std::cout << "Error:\nWaiting for ADD, SEARCH or EXIT." << std::endl;
	}
}

