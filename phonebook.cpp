
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

	if (_currentContacts >= 8) {

		_contact[0] = _contact[7];
		_currentContacts = 8;
	
	} else {
			
		Contact newContact;

		// std::cout << "Enter First Name: ";
		newContact.firstName = getInputString( "Enter First Name: " );
		
		// std::cout << "Enter Last Name: ";
		newContact.lastName = getInputString( "Enter Last Name: " );
		
		// std::cout << "Enter Nickname: ";
		newContact.nickName = getInputString( "Enter Nickname: " );

		// std::cout << "Enter Phone Number: ";
		newContact.phoneNumber = getInputNumber( "Enter Phone Number: " );
		
		// std::cout << "Enter Your Darkest Secret: " << std::endl;
		newContact.darkestSecret = getInputString( "Enter Your Darkest Secret: " );
		
		_contact[_currentContacts] = newContact;
		_currentContacts++;

		std::cout << "Contact entry success" << std::endl;

	}
}

std::string PhoneBook::getInputString( const std::string& prompt ) {

	std::string input;

	while ( true ) {

		std::cout << prompt;
		std::cin >> input;

		if (isAlphabetic( input )) {
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

	for ( int i = 0; i < _currentContacts; i++ ) {

		std::cout << ( _currentContacts + 1 )
		resizeString( _contact[i].firstName );
		std::cout << "|";
		resizeString( _contact[i].lastName );
		std::cout << "|";
		resizeString( _contact[i].nickName );
		// std::cout << "|";
		// resizeString( _contact[i].phoneNumber );
		// std::cout << "|";
		// resizeString( _contact[i].darkestSecret);
		std::cout << "|" << std::endl;

	}
}

Contact::Contact() {

	std::cout << "Contact constructor called: " << std::endl;

}

Contact::~Contact() {

	std::cout << "Contact Destructor called: " << std::endl;

}
