/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 09:53:06 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/01 11:12:25 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
   Zombie *horde = zombieHorde(5,"aelbouz");
   if (!horde)
      std::cout << "faild to creat a hord\n";
   int i = 0;
   while (i < 5)
   {
      horde->announce();
      i++;
   }
   delete[] (horde);
}