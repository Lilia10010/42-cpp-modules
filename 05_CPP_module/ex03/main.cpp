/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:49:13 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 18:19:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

int main()
{
    std::cout << "\n========== TEST 1: INTERN CREATES FORMS ==========\n" << std::endl;

    Intern intern;

    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("shrubbery creation", "Garden");
    AForm* f3 = intern.makeForm("presidential pardon", "Alice");
    AForm* f4 = intern.makeForm("unknown form", "???");

    std::cout << "\n========== TEST 2: PRINT FORMS ==========\n" << std::endl;

    if (f1) std::cout << *f1 << std::endl;
    if (f2) std::cout << *f2 << std::endl;
    if (f3) std::cout << *f3 << std::endl;
    if (f4) std::cout << *f4 << std::endl;

    std::cout << "\n========== TEST 3: BUREAUCRAT ACTIONS ==========\n" << std::endl;

    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 50);
    Bureaucrat low("Low", 150);

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;

    std::cout << "\n========== TEST 4: SIGN FORMS ==========\n" << std::endl;

    if (f1) mid.signForm(*f1);  // pode falhar dependendo da grade
    if (f2) boss.signForm(*f2); // deve funcionar
    if (f3) low.signForm(*f3);  // deve falhar

    std::cout << "\n========== TEST 5: EXECUTE FORMS ==========\n" << std::endl;

    try {
        if (f1) boss.executeForm(*f1);
    } catch (std::exception& e) {
        std::cout << "Execution error: " << e.what() << std::endl;
    }

    try {
        if (f2) boss.executeForm(*f2);
    } catch (std::exception& e) {
        std::cout << "Execution error: " << e.what() << std::endl;
    }

    try {
        if (f3) boss.executeForm(*f3);
    } catch (std::exception& e) {
        std::cout << "Execution error: " << e.what() << std::endl;
    }

    std::cout << "\n========== TEST 6: CLEANUP ==========\n" << std::endl;

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    std::cout << "\n========== END o/ ==========\n" << std::endl;

    return 0;
}