/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/18 11:27:01 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "---- Creating ScavTrap ----" << std::endl;
    ScavTrap b("ScavTrap");
    std::cout << "---- Actions ----" << std::endl;
    b.attack("target");
    b.takeDamage(30);
    b.beRepaired(20);
    b.guardGate();

    std::cout << "---- Destruction ----" << std::endl;
    return 0;
}

