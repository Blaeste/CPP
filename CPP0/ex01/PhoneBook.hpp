/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:18:28 by eschwart          #+#    #+#             */
/*   Updated: 2025/10/10 10:08:33 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact				_contacts[8];
		int					_currentIndex;
		int					_totalContacts;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact( const Contact &contact );
		Contact	getContact( int index ) const;
		int		getTotalContacts() const;
		void	displayContacts() const;
		STRING	truncString(const STRING &str) const;
};
