/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:35:39 by lpaula-n        #+#    #+#             */
/*   Updated: 2025/12/14 17:37:58 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

void Zombie::annouce(void)
{
    std::cout << "🧟 " << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}