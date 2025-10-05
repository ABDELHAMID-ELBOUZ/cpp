/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:11:57 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/04 14:36:38 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout <<  "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info( void )
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}
void Harl::warning( void )
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}
void Harl::error( void )
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4])(void) =
    {
      &Harl::debug,
      &Harl::info,
      &Harl::warning,
      &Harl::error
    };
    int index = -1;
    switch (level.length())
    {
    case 4:
        if (level == "INFO")
            index = 0;
        break;
    case 5:
        if (level == "DEBUG")
            index = 1;
        else if (level == "ERROR")
            index = 2;
        break;
    case 7:
        if (level == "WARNING")
            index = 3;
    default:
        break;
    }
    if (index >= 0 && index < 4)
        (this->*functions[index])();
    else 
        std::cout << "[INVALID] Unknown complaint level: " << level << std::endl;
}