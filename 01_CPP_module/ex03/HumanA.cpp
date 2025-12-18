/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:41:11 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/17 22:16:25 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{ 
    this->name = name;
}

void HumanA::attack() const
{
        std::cout << name << " attacks with their " << _weapon.getType() << std::endl;  
}

void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}
