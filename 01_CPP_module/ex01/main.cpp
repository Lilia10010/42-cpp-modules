/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:38:07 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/16 22:29:04 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int i;
    int count = 5;

    Zombie* horde = zombieHorde(count, "Zombie");
    if (!horde)
        return (1);

    i = 0;
    while (i < count)
    {
        horde[i].ennouce();
        std::cout << i + 1;
        ++i;
    }

    delete[] horde;

    return (0);
}