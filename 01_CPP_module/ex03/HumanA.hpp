/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:02:03 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/21 14:03:03 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	humanName;
		Weapon&		humanWeapon;

    public:
		HumanA(std::string name, Weapon &weapon);
		void setWeapon(Weapon weapon);
        void attack() const;

};

#endif