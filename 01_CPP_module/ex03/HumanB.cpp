/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:41:11 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/17 22:22:58 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) { this->name = name; }

void HumanB::attack() const
{
    if (this->weapon)
    {
        std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
