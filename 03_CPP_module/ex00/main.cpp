/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:28:55 by microbiana        #+#    #+#             */
/*   Updated: 2026/01/12 12:33:02 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("CL4P-TP");

    a.attack("target dummy");
    a.takeDamage(5);
    a.beRepaired(3);

    a.takeDamage(20);
    a.attack("target");
    a.beRepaired(5);

    return 0;
}
