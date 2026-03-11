/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:38:24 by lpaula-n        #+#    #+#             */
/*   Updated: 2026/02/27 11:38:01 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;

    if (this != &other)
        type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal desctructor called" << std::endl;
}

std::string Animal::getType() const 
{
    return (type);
}

// void Animal::makeSound() const 
// {
//     std::cout << "* generic animal sound *" << std::endl;
// }

