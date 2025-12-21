/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:41:11 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/21 14:03:51 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : humanName(name), humanWeapon(weapon) {}

void HumanA::attack() const
{
        std::cout << humanName
        << " attacks with their "
        << humanWeapon.getType() << std::endl;  
}

void HumanA::setWeapon(Weapon weapon)
{
    this->humanWeapon = weapon;
}
