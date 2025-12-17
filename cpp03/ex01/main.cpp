/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/17 13:21:19 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "---- Creating ClapTrap ----" << std::endl;
    ClapTrap a("CL4P");
    std::cout << "---- Creating ScavTrap ----" << std::endl;
    ScavTrap b("SC4V");
    std::cout << "---- Actions ----" << std::endl;
    b.attack("Intruder");
    b.takeDamage(30);
    b.beRepaired(20);
    b.guardGate();

    std::cout << "---- Destruction ----" << std::endl;
    return 0;
}

