/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:34:44 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/07 11:27:50 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
        std::cout << "enter one level (DEBUG,INFO,WARNING,ERROR)" << std::endl;
    harl.complain(av[1]);
}