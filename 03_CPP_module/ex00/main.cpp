/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:28:55 by lpaula-n        #+#    #+#             */
/*   Updated: 2026/01/12 12:33:02 by lpaula-n       ###   ########.fr       */
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
