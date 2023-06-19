/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:38:31 by vgejno            #+#    #+#             */
/*   Updated: 2023/06/19 20:27:20 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>

bool isNumeric(const std::string& str);

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
		
};

# endif