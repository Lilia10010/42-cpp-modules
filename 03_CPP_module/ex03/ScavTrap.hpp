/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:00:43 by microbiana        #+#    #+#             */
/*   Updated: 2026/02/08 16:04:56 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap();                       
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);  
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();


    void attack(const std::string& target);

    void guardGate();
};

#endif
