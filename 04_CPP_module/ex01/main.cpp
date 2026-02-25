/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:40:53 by microbiana        #+#    #+#             */
/*   Updated: 2026/02/25 12:10:29 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

    std::cout << "=== Test 1: Array of Animals ===" << std::endl;

    Animal* animals[4];

    for (int i = 0; i < 2; i++)
    {
        animals[i] = new Dog();
        std::cout << i << "-------------------" << std::endl;

    }

    for (int i = 2; i < 4; i++)
    {
        animals[i] = new Cat();
         std::cout << i << "-------------------" << std::endl;
    }

    for (int i = 0; i < 4; i++)
        delete animals[i]; // 🔴 destruição via ponteiro base


    std::cout << "\n=== Test 2: Deep Copy ===" << std::endl;

    Dog original;
    original.getBrain()->setIdea(0, "Chase cats");

    Dog copy = original;

    std::cout << "Original idea: "
              << original.getBrain()->getIdea(0) << std::endl;

    std::cout << "Copy idea: "
              << copy.getBrain()->getIdea(0) << std::endl;

    copy.getBrain()->setIdea(0, "Eat food");

    std::cout << "After modification:" << std::endl;
    std::cout << "Original idea: "
              << original.getBrain()->getIdea(0) << std::endl;

    std::cout << "Copy idea: "
              << copy.getBrain()->getIdea(0) << std::endl;

    return 0;
}