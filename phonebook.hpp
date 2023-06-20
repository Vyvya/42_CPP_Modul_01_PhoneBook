/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vg <vg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:38:31 by vgejno            #+#    #+#             */
/*   Updated: 2023/06/19 23:37:42 by vg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

bool isNumeric(const std::string& str);
bool isAlphabetic(const std::string& str);

class Contact
{
	public:

		Contact( void );
		~Contact( void );

		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

class PhoneBook {

	public:

		PhoneBook( void );
		~PhoneBook( void );

	void addContact();
	void displayAllContacts();

	private:

		Contact	_contact[8];
		int _currentContacts;

		std::string getInputString( const std::string& prompt );
		std::string getInputNumber( const std::string& prompt );

};

# endif
