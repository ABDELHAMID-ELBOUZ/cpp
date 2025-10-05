/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:47:00 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/02 14:56:06 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &Name,Weapon &WeaponRef) : weapon(WeaponRef)
{
    name = Name;
    // weapon = WeaponRef;
}

void HumanA::attack() const
{
    std::cout << name << " attacks with their" << weapon.getType() << std::endl;
}