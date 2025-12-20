/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:10:04 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/19 12:13:01 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "----- Correct polymorphism -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << j->getType() << std::endl;
    i->makeSound();
    std::cout << i->getType() << std::endl;
    j->makeSound();
    delete meta;
    delete j;
    delete i;
    std::cout << "\n----- Wrong polymorphism -----" << std::endl;
    const WrongAnimal* w = new WrongCat();
    w->makeSound();
    delete w;
    return 0;
}
