/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:52:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/06/19 21:16:13 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*utility function that checks whether a given string contains only 
numeric characters. It takes a const std::string& as input, 
which is a reference to a constant std::string object.*/

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
		// std::cout << "Enter:" << std::endl;
		std::cout << "ADD	to add a new contact" << std::endl;
		std::cout << "SEARCH	to display saved contacts" << std::endl;
		std::cout << "EXIT	to quit" << std::endl;
		
		std::cin >> input;
		
		if ( input == "ADD" ) {
			
			phoneBook.addContact();
			std::cout << "Contact added" << std::endl;
		}
		
		else if ( input == "SEARCH" ) {

			phoneBook.displayAllContacts();
			std::cout << "Select index: " << std::endl;
			std::cin >> index;

			if (isNumeric(index)) {
				
				std::cout << "Input should be a number" << std::endl;
			}
		}
		else if ( input == "EXIT" ) {
			return 0;
		}
		
	}
	return 0;
}