
#include "phonebook.hpp"

/*utility function that checks whether a given string contains only
numeric characters. It takes a const std::string& as input,
which is a reference to a constant std::string object.*/

void resizeString( const std::string& str ) {

	std::string resizedString = str;

	if ( str.size() == 10) {

		std::cout << str;

	} else if ( str.size() > 10 ) {

		std::string resizedString = str.substr( 0, 9 );
		std::cout << resizedString << ".";

	} else {

		std::string resizedString = str;
		resizedString.resize( 10, ' ' );
		std::cout << resizedString;
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
	std::string index;


	while ( true  ) {

		std::cout << std::endl;
		std::cout << "PHONEBOOK" << std::endl;
		std::cout << std::endl;
		std::cout << "Enter:" << std::endl;
		std::cout << "ADD	-> to add a new contact" << std::endl;
		std::cout << "SEARCH	-> to display saved contacts" << std::endl;
		std::cout << "EXIT	-> to quit" << std::endl;

		std::cin >> input;

		if ( input == "ADD" ) {

			phoneBook.addContact();
			std::cout << "Contact added" << std::endl;
		
		} else if ( input == "SEARCH" ) {

			phoneBook.displayAllContacts();
			std::cout << "Select index: " << std::endl;
			std::cin >> index;

			if (!isNumeric( index )) {

				std::cout << "Input should be a number" << std::endl;
				
			} else {
				
				phoneBook.displayAllContacts();
			}
		
		} else if ( input == "EXIT" ) {
			
			return 0;
		
		} else {
			
			std::cout << "Invalid command. Please retry" << std::endl;
		} 

	}
	return 0;
}
