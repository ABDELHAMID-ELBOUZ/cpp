/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 09:53:06 by aelbouz           #+#    #+#             */
/*   Updated: 2025/09/27 09:56:31 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* Zombie1 = newZombie("foo");
    Zombie1->announce();
    delete(Zombie1);
    
    randomChump("looo");
}