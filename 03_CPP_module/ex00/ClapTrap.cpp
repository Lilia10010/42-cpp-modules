/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:05:39 by microbiana        #+#    #+#             */
/*   Updated: 2026/01/12 12:31:39 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap" << _name << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    //verificar se tem vida e energia antes do ataque
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name
                  << " cannot attack (no hit points or energy)" << std::endl;
        return ;
    }

    _energyPoints--;

    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

// rebe o dano e contra a vida
void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;

    if (_hitPoints < 0)
        _hitPoints = 0;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " damage, hit points now " << _hitPoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name
                  << " cannot repair (no hit points or energy)" << std::endl;
        return;
    }

    _energyPoints--;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name
              << " repairs itself for "
              << amount << " hit points!" << std::endl;
}
