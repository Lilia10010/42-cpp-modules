/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:21:48 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 18:17:51 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
    🔥 Funções auxiliares (factory functions)

    Cada uma cria um tipo específico de formulário
    Retornam AForm* → POLIMORFISMO
*/

AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// --- special members ---
Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

Intern::~Intern() {}

/*
    🧠 typedef

    Define um tipo para ponteiro de função:

    função que:
    - recebe std::string
    - retorna AForm*
*/
typedef AForm* (*FormCreator)(const std::string&);

/*
    🧠 makeForm

    Objetivo:
    - Escolher QUAL objeto criar baseado em string
    - Retornar ponteiro para classe base (AForm*)

    Conceitos:
    ✔ Polimorfismo
    ✔ Abstração
    ✔ Factory Pattern
*/
AForm* Intern::makeForm(const std::string& name, const std::string& target) {

    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] = {
        createShrubbery,
        createRobotomy,
        createPardon
    };

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {

            std::cout << "Intern creates "
                      << formNames[i]
                      << " targeting "
                      << target
                      << std::endl;

            return creators[i](target);
        }
    }

    std::cout << "Error: form \"" << name << "\" not found" << std::endl;
    return NULL;
}