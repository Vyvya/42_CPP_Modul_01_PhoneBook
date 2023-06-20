/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vg <vg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:52:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/06/19 23:53:13 by vg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook( void ) {

	std::cout << "PhoneBook Constructor called" << std::endl;
	_currentContacts = 0;
	// return;
}

PhoneBook::~PhoneBook( void ) {

	std::cout << "PhoneBook Destructor called" << std::endl;
	// return;
}

void PhoneBook::addContact() {
	//implementation

	std::string input;

	if (_currentContacts < 8) {
		Contact newContact;

		bool isValidInput = false;

		while ( !isValidInput ) {

			std::cout << "Enter First Name: ";
			std::cin >> input;

			if ( isAlphabetic( input ) ) {

				newContact.firstName = input;
				bool isValidInput = true;
			}

			else {

				std::cout << "Input should be alphabetic characters" << std::endl;
			}
		}

		bool isValidInput = false;

		while ( !isValidInput ) {

			std::cout << "Enter Last Name: ";
			std::cin >> input;

			if ( isAlphabetic( input )) {

				newContact.lastName = input;
				bool isValidInput = true;
			}

			else {

				std::cout << "Input should be alphabetic characters" << std::endl;
			}

			std::cout << "Enter Nickname: ";
			std::cin >> newContact.nickName;


			bool isValidInput = false;

			std::cout << "Enter Phone Number: ";
			std::cin >> input;

			if ( isNumeric(input) ) {

				newContact.phoneNumber = input;
				isValidInput = true;
			}

			else {

				std::cout << "Input should be a number" << std::endl;
				return;

			}
		}

		bool isValidInput = false;

		while ( !isValidInput ) {

			std::cout << "Enter Your Darkest Secret: " << std::endl;
			std::cin >> input;

			if ( isAlphabetic( input )) {

				newContact.darkestSecret = input;
				isInvalid = true;
			}
		}

		_contact[_currentContacts] = newContact;
		_currentContacts++;

		std::cout << "Contact entry success" << std::endl;

	}
	else {

		_currentContacts = 0;
		PhoneBook::addContact();
	}
}

std::string PhoneBook::getInputString( const std::string& prompt ) {

	std::string input;

	while ( true ) {

		std::cout << prompt;
		std::cin >> input;

		if (is Alphabetic( input )) {
			return input;
		} else {
			std::cout << "Input should be alphabetic characters." << std::endl;
		}
	}
}

std::string PhoneBook::getInputNumber( const std::string& prompt ) {
	std::string input;

	while ( true ) {
		std::cout << prompt;
		std::cin >> input;

		if ( isNumeric( input )) {
			return input;
		} else {
			std::cout << "Input should be a number." << std::endl;
		}
	}
}


void PhoneBook::displayAllContacts() {
	//implementation
}

Contact::Contact() {

	std::cout << "Contact constructor called: " << std::endl;

}

Contact::~Contact() {

	std::cout << "Contact Destructor called: " << std::endl;

}
