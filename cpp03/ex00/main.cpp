/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/18 11:26:36 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("claptrap");
    a.attack("Target");
    a.takeDamage(3);
    a.beRepaired(5);
    a.takeDamage(20);
    a.attack("Enemy");
    a.beRepaired(5);
    return 0;
}
