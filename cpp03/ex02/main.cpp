/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/17 13:23:20 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "---- Creating ClapTrap ----" << std::endl;
    ClapTrap a("CL4P");
    std::cout << "---- Creating ScavTrap ----" << std::endl;
    ScavTrap b("SC4V");
    std::cout << "---- Creating FragTrap ----" << std::endl;
    FragTrap c("FR4G");
    std::cout << "---- Actions ----" << std::endl;
    c.attack("Boss");
    c.takeDamage(40);
    c.beRepaired(20);
    c.highFivesGuys();
    std::cout << "---- Destruction ----" << std::endl;
    return 0;
}


