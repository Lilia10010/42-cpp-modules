/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:04:48 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/16 22:24:31 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name(name) { }

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " is destroyed" << std::endl;
}

void Zombie::ennouce(void)
{
    std::cout << "🧟 " << name << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}