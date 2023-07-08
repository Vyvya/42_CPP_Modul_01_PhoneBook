
#include "phonebook.hpp"

PhoneBook::PhoneBook( void ) {

	std::cout << "PhoneBook Constructor called" << std::endl;
	_currentContacts = 0;
}

PhoneBook::~PhoneBook( void ) {

	std::cout << "PhoneBook Destructor called" << std::endl;
}

//implementation 
void PhoneBook::addContact() {
	
	std::string input;
	Contact newContact;

	newContact.firstName = getInputString( "Enter First Name: " );
	newContact.lastName = getInputString( "Enter Last Name: " );
	newContact.nickName = getInputString( "Enter Nickname: " );
	newContact.phoneNumber = getInputNumber( "Enter Phone Number: " );

	std::cout << "Enter Your Darkest Secret: ";
	std::getline( std::cin >> std::ws, newContact.darkestSecret);

	if( _currentContacts < 8) {

		_contact[_currentContacts] = newContact;
		_currentContacts++;

	} else {

		int oldestContact = ( _currentContacts % 8 );
		_contact[oldestContact] = newContact;
		_currentContacts++;
	}

	std::cout << "Contact entry success" << std::endl;
	return;
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
			std::cout << "Input should be a number" << std::endl;
		}
	}
}


void PhoneBook::displayAllContacts() {

	std::string index;

	std::cout << std::setw( 10 ) << "Index" << "|";
	std::cout << std::setw( 10 ) << "First Name" << "|";
	std::cout << std::setw( 10 ) << "Last Name" << "|";
	std::cout << std::setw( 10 ) << "Nickname" << "|" << std::endl;

	if ( _currentContacts == 0 ) {

		for (int i = 0; i < 4; i++ ) {

			printNumber( _currentContacts);
			std::cout << "|";

		}

		std::cout  << std::endl << std::endl;
		return;

	} else {

		if ( _currentContacts <= 8) {

			for ( int i = 1; i <= _currentContacts; i++ ) {

				printNumber( i );
				std::cout << "|";
				resizeString( _contact[i - 1].firstName );
				std::cout << "|";
				resizeString( _contact[i - 1].lastName );
				std::cout << "|";
				resizeString( _contact[i - 1].nickName );
				std::cout << "|" << std::endl;
			}

		} else {

			for ( int i = 1; i <= 8 ; i++ ) {

				printNumber( i );
				std::cout << "|";
				resizeString( _contact[i - 1].firstName );
				std::cout << "|";
				resizeString( _contact[i - 1].lastName );
				std::cout << "|";
				resizeString( _contact[i - 1].nickName );
				std::cout << "|" << std::endl;
			}
		}

		std::cout << std::endl;

	}

	int flag = false;

	while( !flag ) {

			std::cout << "Select entry index: " << std::endl;
			std::cin >> index;

			if (std::cin.eof()) {
				
				std::cin.clear();
				clearerr(stdin);
				break;
			}

			if (!isNumeric( index )) {

				std::cout << "Input should be a number" << std::endl;
				flag = false;

			} else {
				
				int numIndex = atoi(index.c_str());
				if ( displayOneContact( numIndex ) ) {

					flag = false;

				} else {

					flag = true;

				}
			}
	}
	return;	
}

int PhoneBook::displayOneContact( int index ) {

	int flag = false;

	while ( !flag ) {
		
		if( index >= 1 && index <= 8 && index <= _currentContacts ) {

			std::cout << "Displaying selected contact: " << index << std::endl << std::endl;
			std::cout << "First Name: " << _contact[index - 1].firstName << std::endl;
			std::cout << "Last Name: " << _contact[index - 1].lastName << std::endl;
			std::cout << "Nickname: " << _contact[index - 1].nickName << std::endl;
			std::cout << "Phone Number: " << _contact[index - 1].phoneNumber << std::endl;
			std::cout << "Darkest Secret: " << _contact[index - 1].darkestSecret << std::endl << std::endl;

			flag = true;

		} else if( index > _currentContacts ) {

			std::cout << "There are currently: " << _currentContacts << " entires in the PhoneBook" << std::endl << std::endl;
			return 1;

		} else {

			std::cout << "Input should be a number between 1 and 8" << std::endl << std::endl;
			return 1;

		}	
	}
	return 0;
}

Contact::Contact() {

	// std::cout << "Contact constructor called: " << std::endl;

}

Contact::~Contact() {

	// std::cout << "Contact Destructor called: " << std::endl;

}
