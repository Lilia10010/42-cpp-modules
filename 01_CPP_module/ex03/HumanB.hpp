/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:24:58 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/21 14:06:15 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	humanName;
		Weapon*		humanWeapon;

	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void) const;

};

#endif