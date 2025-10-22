/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:18:09 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/10 10:13:45 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0) {}
PhoneBook::~PhoneBook() {}

STRING	PhoneBook::truncString(const STRING &str) const {

	return (str.length() > 10 ? str.substr(0, 9) + "." : str);
}

void	PhoneBook::addContact( const Contact &contact ) {
	_contacts[_currentIndex] = contact;
	_currentIndex = (_currentIndex + 1) % 8;
	if ( _totalContacts < 8 )
		_totalContacts++;
}

Contact	PhoneBook::getContact( int index ) const {
	if (index < 0 || index >= _totalContacts)
		throw std::out_of_range("Invalid contact index");
	return _contacts[index];
}

int		PhoneBook::getTotalContacts() const {
	return _totalContacts;
}

void	PhoneBook::displayContacts() const {

	std::cout
		<< std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	std::cout << std::endl;
	for ( int i = 0; i < this->_totalContacts; i++)
	{
		Contact current = getContact(i);

		std::cout
			<< std::setw(10) << i << "|"
			<< std::setw(10) << truncString(  current.getField(FIRST_NAME)) << "|"
			<< std::setw(10) << truncString(  current.getField(LAST_NAME)) << "|"
			<< std::setw(10) << truncString(  current.getField(NICKNAME))
			<< std::endl;
	}
}
