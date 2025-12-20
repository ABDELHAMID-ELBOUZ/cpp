/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:10:04 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/19 12:29:46 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "----- Array of Animals -----" << std::endl;
    Animal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 10; i++)
        delete animals[i];
    std::cout << "\n----- Deep copy test -----" << std::endl;
    Dog original;
    original.getBrain()->setIdea(0, "I love bones");
    Dog copy = original;
    copy.getBrain()->setIdea(0, "I love cats");
    std::cout << "Original idea: "
              << original.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: "
              << copy.getBrain()->getIdea(0) << std::endl;
    return 0;
}