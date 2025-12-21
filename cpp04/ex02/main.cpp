/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:10:04 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/21 11:33:14 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    dog->makeSound();
    cat->makeSound();
    delete dog;
    delete cat;
    return 0;
}
