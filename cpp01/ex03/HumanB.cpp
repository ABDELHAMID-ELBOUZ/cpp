/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:47:07 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/07 11:34:52 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &Name)
{
    name = Name;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon &WeaponRef)
{
    weapon = &WeaponRef;
}

void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
