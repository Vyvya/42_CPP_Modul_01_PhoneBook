
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

bool isNumeric( const std::string& str );
bool isAlphabetic( const std::string& str );
void resizeString( const std::string& str );
void printNumber( int num );

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
	int displayOneContact( int index );

	private:

		Contact	_contact[8];
		int _currentContacts;

		std::string getInputString( const std::string& prompt );
		std::string getInputNumber( const std::string& prompt );

};

# endif
