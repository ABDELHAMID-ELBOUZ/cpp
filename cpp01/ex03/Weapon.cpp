/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:55:46 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/01 15:37:32 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &Type)
{
    type = Type;
}

const std::string &Weapon::getType() const
{
    return (type);
}

void Weapon::setType(const std::string &newType)
{
    type = newType;
}