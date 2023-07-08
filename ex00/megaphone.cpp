/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:52:47 by vgejno            #+#    #+#             */
/*   Updated: 2023/07/08 15:49:45 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	char c = 0;
	std::string str;
	bool more = true;

	while (more) {
		std::getline(std::cin, str);
		
		if (str.empty()) {
			
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			return 0;
			// continue;
			
		} else {
			
			more = false;
		}
		for (size_t i = 0; i < str.length(); i++)
		{

			c = toupper(str[i]);
			std::cout << c;
		}
	}
	std::cout <<'\n';
	return 0;
}