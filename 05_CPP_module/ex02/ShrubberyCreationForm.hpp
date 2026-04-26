/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:37:44 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 17:37:48 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

/*
    Classe concreta

    Objetivo:
    - Criar um arquivo com ASCII trees 🌳
    - Demonstra uso de I/O (arquivo)

    OOP:
    ✔ Herança (AForm)
    ✔ Polimorfismo (override execute)
*/

class ShrubberyCreationForm : public AForm {
private:
    std::string _target; // encapsulamento

public:
    // construtor recebe o alvo
    ShrubberyCreationForm(const std::string& target);

    // forma canônica
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    // polimorfismo
    void execute(Bureaucrat const & executor) const;
};

#endif