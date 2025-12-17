/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:44:01 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/17 15:20:04 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;

    std::cout << "ScavTrap " << Name << " Constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assignment operator called." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " Destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " has no hit points left!" << std::endl;
        return ;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy points left!" << std::endl;
        return ;
    }
    energyPoints--;
    std::cout << "ScavTrap " << Name << " ferociously attacks "
              << target << ", causing " << attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name
              << " is now in Gate keeper mode." << std::endl;
}
