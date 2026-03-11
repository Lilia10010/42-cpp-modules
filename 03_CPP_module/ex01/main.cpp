/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:12:24 by lpaula-n        #+#    #+#             */
/*   Updated: 2026/01/23 15:12:27 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Serena");

    a.attack("enemy");
    a.takeDamage(30);
    a.beRepaired(20);
    a.guardGate();

    return 0;
}
