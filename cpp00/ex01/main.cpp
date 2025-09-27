/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:35:25 by aelbouz           #+#    #+#             */
/*   Updated: 2025/09/21 14:31:21 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook;
	std::string cmd;
	while (1)
	{
		std :: cout << "write a command (ADD,SEARCH,EXIT):"  ;
		if (!std::getline(std::cin, cmd))
			return (1);
		if (cmd == "ADD")
			PhoneBook.AddContact();
		if (cmd == "SEARCH")
			PhoneBook.SearchContact();
		if (cmd == "EXIT")
			exit(0);
	}
}