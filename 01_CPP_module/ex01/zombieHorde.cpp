/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:53:42 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/16 22:25:52 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i;

    if (N <= 0)
        return (NULL);

    Zombie* horde = new Zombie[N];

    i = 0;
    while (i < N)
    {
        horde[i].setName(name);
        ++i;
    }

    return (horde);
}
