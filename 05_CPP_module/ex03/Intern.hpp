/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:21:42 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 18:05:22 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

/*
    Classe Intern

    Responsabilidade:
    - Criar formulários dinamicamente baseado em string

    Conceito usado:
    - Factory Pattern (criação desacoplada)
*/

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();


    AForm* makeForm(const std::string& name, const std::string& target);
};

#endif