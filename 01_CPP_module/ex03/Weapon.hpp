/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:44:59 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/21 13:55:11 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string weaponType;

    public:
        Weapon(std::string initialType);
        void setType(std::string newType);
        const std::string& getType(void) const;
};

#endif
