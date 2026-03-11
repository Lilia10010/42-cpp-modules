/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:21:08 by lpaula-n        #+#    #+#             */
/*   Updated: 2025/12/16 21:24:24 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main()
{
    Zombie* heapZombie = newZombie("heapZombie");
    heapZombie->annouce();
    delete heapZombie;

    randomChump("StackZombie");
    
    return (0);
}