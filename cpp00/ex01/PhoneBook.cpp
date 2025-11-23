/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:32:25 by aelbouz           #+#    #+#             */
/*   Updated: 2025/11/23 13:58:35 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

void PhoneBook::addContact()
{
	std::string first;
	std::string last;
	std::string nick;
	std::string phone;
	std::string darkest;

	while (first.length() == 0)
	{
		std::cout << "First name: ";
		if (!std::getline(std::cin, first))
			return;
	}
	while (last.length() == 0)
	{
		std::cout << "Last name: ";
		if (!std::getline(std::cin, last))
			return;
	}
	while (nick.length() == 0)
	{
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, nick))
			return;
	}
	while (phone.length() == 0)
	{
		std::cout << "Phonee number: ";
		if (!std::getline(std::cin, phone))
			return;
	}
	while (darkest.length() == 0)
	{
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, darkest))
			return;
	}
	contacts[index].setContact(first,last,nick,phone,darkest);
	index = (index + 1) % 8;
	if (count < 8)
		count++;
    std::cout << "✅ Contact added successfully!\n";
}

void PhoneBook::searchContact()
{
	int i = 0;
	std::string input;
	int index;
	if (count == 0)
	{
            std::cout << "PhoneBook is empty." << std::endl;
            return;
	}
	else
	{
		std::cout << std::setw(10) << "Index" << "|"
                  << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|"
                  << std::setw(10) << "Nickname" << std::endl;
		while (i < count)
		{
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << contacts[i].getFirstName().substr(0,10) << "|"
                  << std::setw(10) << contacts[i].getLastName().substr(0,10)<< "|"
                  << std::setw(10) << contacts[i].getNickName().substr(0,10)<< std::endl;
				  i++;
   		}
	}
	std :: cout << "Entre Index:";
	if (!std::getline(std::cin, input))
			return ;
	if (input.length() > 1 || !isdigit(input[0]))
	{
		std::cout<<"invalid index"<<std::endl;
		return ;
	}
	index = input[0] - '0';
	if (index < 0 || index >= count)
	{
		std::cout<<"invalid index"<<std::endl;
		return ;
	}
	Contact c = contacts[index];
	std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}
