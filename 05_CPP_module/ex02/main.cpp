/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:49:13 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 17:59:10 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("shrubbery creation", "Garden");
    AForm* f3 = intern.makeForm("presidential pardon", "Alice");
    AForm* f4 = intern.makeForm("unknown form", "???");

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    return 0;
}