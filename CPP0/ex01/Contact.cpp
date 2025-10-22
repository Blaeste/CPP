/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:20:00 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/09 10:11:15 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setField( ContactField type, const STRING &value ) {
	switch ( type ) {
		case FIRST_NAME: _firstName = value; break;
		case LAST_NAME: _lastName = value; break;
		case NICKNAME: _nickname = value; break;
		case PHONE_NUMBER: _phoneNumber = value; break;
		case DARKEST_SECRET: _darkestSecret = value; break;
	}
}

STRING	Contact::getField( ContactField type ) const {
	switch ( type ) {
		case FIRST_NAME: return _firstName;
		case LAST_NAME: return _lastName;
		case NICKNAME: return _nickname;
		case PHONE_NUMBER: return _phoneNumber;
		case DARKEST_SECRET: return _darkestSecret;
	}
}
