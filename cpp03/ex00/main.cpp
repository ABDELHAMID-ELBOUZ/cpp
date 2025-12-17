/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:33 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/17 11:38:40 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Alpha");

    a.attack("Target");
    a.takeDamage(3);
    a.beRepaired(5);
    a.takeDamage(20);
    a.attack("Enemy");
    a.beRepaired(5);

    return 0;
}
