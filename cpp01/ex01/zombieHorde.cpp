/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:16:15 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/01 11:12:11 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) 
{
    if (N <= 0) {
        std::cout << "Error: Number of zombies must be positive" << std::endl;
        return nullptr;
    }

    Zombie *horde = new Zombie[N];
    int i = 0;
    while (i < N) 
    {
        horde[i].SetName(name);
        i++;
    }
    return (horde);
}