/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/18 11:27:36 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "---- Creating FragTrap ----" << std::endl;
    FragTrap c("FragTrap");
    std::cout << "---- Actions ----" << std::endl;
    c.attack("target");
    c.takeDamage(40);
    c.beRepaired(20);
    c.highFivesGuys();
    std::cout << "---- Destruction ----" << std::endl;
    return 0;
}


