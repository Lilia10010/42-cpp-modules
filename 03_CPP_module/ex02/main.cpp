/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:40:34 by microbiana        #+#    #+#             */
/*   Updated: 2026/02/08 15:48:45 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap a("Fraggy");
    FragTrap b(a);
    FragTrap c;

    c = a;

    a.attack("target");
    a.highFivesGuys();

    return 0;
}
