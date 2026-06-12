/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:05:43 by aelbouz           #+#    #+#             */
/*   Updated: 2026/06/12 10:49:23 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
	{
		Bureaucrat bob("Bob", 150);
		// bob.incrementGrade();
		bob.decrementGrade();
		
	}
	catch(std::exception& e)
	{
        std::cout << "Exception: " << e.what() << std::endl;

	}
	
}
