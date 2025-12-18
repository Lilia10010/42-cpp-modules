/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:02:03 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/17 22:17:32 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		&_weapon;
		std::string	name;

    public:
		HumanA(std::string name, Weapon &Weapon);
		void setWeapon(Weapon weapon);
        void attack() const;

};

#endif