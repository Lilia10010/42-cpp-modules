/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:40:34 by lpaula-n        #+#    #+#             */
/*   Updated: 2026/02/08 15:48:45 by lpaula-n       ###   ########.fr       */
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
