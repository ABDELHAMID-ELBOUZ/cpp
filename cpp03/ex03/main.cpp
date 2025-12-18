/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/18 11:27:51 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "---- Creating DiamondTrap ----" << std::endl;
    DiamondTrap d("DiamondTrap");
    std::cout << "---- Actions ----" << std::endl;
    d.attack("target");
    d.takeDamage(25);
    d.beRepaired(10);
    d.whoAmI();
    std::cout << "---- Destruction ----" << std::endl;
    return 0;
}
