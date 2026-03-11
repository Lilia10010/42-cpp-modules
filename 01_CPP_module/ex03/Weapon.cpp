/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:50:40 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/21 13:53:09 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string initialType) : weaponType(initialType) {}

void Weapon::setType(std::string newType)
{
    this->weaponType = newType;
}

const std::string& Weapon::getType(void) const
{
    return (weaponType);    
}