/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:38:07 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/16 22:47:19 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int i;
    int count = 0;

    Zombie* horde = zombieHorde(count, "Zombie");
    if (!horde)
        return (1);

    i = 0;
    while (i < count)
    {
        std::ostringstream oss;
        oss << i + 1;
        horde[i].announce(oss.str());
        
        ++i;
    }

    delete[] horde;

    return (0);
}