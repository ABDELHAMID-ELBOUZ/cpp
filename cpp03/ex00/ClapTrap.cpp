/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:51:38 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/17 15:39:54 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name):Name(name),hitPoints(10),energyPoints(10),attackDamage(10)
{
    std::cout << "ClapTrap " << Name << " Constructor called." << std::endl ;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std:: cout << "ClapTrap Copy assignment operator called" << std:: endl;
	Name = obj.Name;
    hitPoints = obj.hitPoints;
    attackDamage = obj.attackDamage;
    energyPoints = obj.energyPoints;
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap  " << Name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " cannot attack." << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << Name << " attacks " << target
              << ", causing " << attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << Name << " takes "
              << amount << " points of damage! "
              << "Hit points left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " cannot be repaired (no hit points)." << std::endl;
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy points left!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << Name << " repairs itself for "
              << amount << " hit points! "
              << "Hit points now: " << hitPoints << std::endl;
}