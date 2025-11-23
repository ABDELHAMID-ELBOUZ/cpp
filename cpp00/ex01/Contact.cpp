/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:20:44 by aelbouz           #+#    #+#             */
/*   Updated: 2025/09/21 17:19:03 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setContact(std::string first_name,std::string last_name,std::string nick_name,std::string phone_number,std::string darkest_secret)
{
	firstname = first_name;
	lastname = last_name;
	nickname = nick_name;
	phonenumber = phone_number;
	darkestsecret = darkest_secret;
}

std::string Contact::getFirstName()
{
		return (firstname);
}
std::string Contact::getLastName()
{
	return (lastname);
}
std::string Contact::getNickName()
{
	return (nickname);
}
std::string Contact::getPhoneNumber()
{
	return (phonenumber);
}
std::string Contact::getDarkestSecret()
{
	return (darkestsecret);
}
