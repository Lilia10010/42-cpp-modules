/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:41:11 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/21 14:19:33 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : humanName(name), humanWeapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon)
{
    humanWeapon = &weapon;
}
void HumanB::attack() const
{
    if (humanWeapon)
    {
        std::cout << humanName
        << " attacks with their "
        << humanWeapon->getType() << std::endl;
    } else{
        std::cout << humanName
        << " attacks with their bare hands" << std::endl;
    }
}

