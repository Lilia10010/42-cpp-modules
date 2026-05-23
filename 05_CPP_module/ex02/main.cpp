/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:49:13 by microbiana        #+#    #+#             */
/*   Updated: 2026/05/23 16:20:39 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void separator() { std::cout << "\n---------------------------\n"; }

int main()
{
    // Shrubbery: sign 145, exec 137
    {
        std::cout << "Test: ShrubberyCreationForm" << std::endl;
        Bureaucrat low("Low", 150);
        Bureaucrat signer("Signer", 140);
        Bureaucrat exec("Exec", 130);

        ShrubberyCreationForm form("Home");
        std::cout << form << std::endl;

        // cannot sign: grade too low
        signer.signForm(form); // should succeed
        exec.executeForm(form); // should succeed

        separator();
    }

    // Robotomy: sign 72, exec 45
    {
        std::cout << "Test: RobotomyRequestForm" << std::endl;
        Bureaucrat signer("Signer", 50); // can sign
        Bureaucrat execGood("ExecGood", 40); // can execute
        Bureaucrat execBad("ExecBad", 100); // cannot execute

        RobotomyRequestForm rform("Bob");
        signer.signForm(rform);
        execGood.executeForm(rform); // expect drilling + success/fail
        execBad.executeForm(rform);  // expect error

        separator();
    }

    // Presidential: sign 25, exec 5
    {
        std::cout << "Test: PresidentialPardonForm" << std::endl;
        Bureaucrat signer("Signer", 1);
        Bureaucrat exec("Exec", 1);

        PresidentialPardonForm pform("Marvin");
        // try executing unsigned
        exec.executeForm(pform); // should report not signed

        signer.signForm(pform);
        exec.executeForm(pform); // should succeed

        separator();
    }

    return 0;
}