/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:19:57 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/09 11:48:04 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <locale>
#include <cstdlib>

#define STRING std::string

enum ContactField {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

class Contact {
	private:
		STRING _firstName;
		STRING _lastName;
		STRING _nickname;
		STRING _phoneNumber;
		STRING _darkestSecret;

	public:
		Contact();
		~Contact();

		void		setField( ContactField type, const STRING &value );
		STRING		getField( ContactField type ) const;
};
