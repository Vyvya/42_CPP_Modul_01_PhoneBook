
#include "phonebook.hpp"

/*utility function that checks whether a given string contains only
numeric characters. It takes a const std::string& as input,
which is a reference to a constant std::string object.*/

void printNumber( int num ) {

	std::string numberString = std::to_string( num );
	std::cout << std::setw( 10 ) << numberString;

	return;
}

void resizeString( const std::string& str ) {

	std::string resizedString = str;

	if ( str.size() == 10) {

		std::cout << str;

	} else if ( str.size() > 10 ) {

		std::string resizedString = str.substr( 0, 9 );
		std::cout << resizedString << ".";

	} else {

		std::cout << std::setw( 10 ) << str;
	}

	return;
}

bool isAlphabetic( const std::string& str ) {

	for (std::string::size_type i = 0; i < str.size(); i++ ) {

		if ( !std::isalpha( str[i] )) {

			return false;
		}
	}

	return true;
}

bool isNumeric( const std::string& str ) {

	for (std::string::size_type i = 0; i < str.size(); i++ ) {

		if ( !std::isdigit( str[i] )) {
			return false;
		}
	}

	return true;
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << std::endl;
	std::cout << "PHONEBOOK" << std::endl << std::endl;

	while ( true  ) {

		std::cout << "Enter:" << std::endl;
		std::cout << "ADD	-> to add a new contact" << std::endl;
		std::cout << "SEARCH	-> to display saved contacts" << std::endl;
		std::cout << "EXIT	-> to quit" << std::endl << std::endl;

		std::cin >> input;

		if ( input == "ADD" ) {

			phoneBook.addContact();
			std::cout << "Contact added" << std::endl << std::endl;
		
		} else if ( input == "SEARCH" ) {

			std::cout << "Displaying all entries:" << std::endl << std::endl;
			phoneBook.displayAllContacts();
		
		} else if ( input == "EXIT" ) {
			
			std::cout << "Phonebook deleted" << std::endl;
			return 0;
		
		} else {
			
			std::cout << "Invalid command. Please retry" << std::endl << std::endl;
		} 

	}
	return 0;
}
