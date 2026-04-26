/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:49:13 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 13:39:20 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat m("Maria", 50);
        Bureaucrat j("Jão", 30);
        Bureaucrat b("Boss", 1);

        Form f("Contract", 40, 20);

        std::cout << f << std::endl;

        std::cout << "----------" << std::endl;

        m.signForm(f);

        std::cout << "----------" << std::endl;

        j.signForm(f);

        std::cout << "----------" << std::endl;

        b.signForm(f);

        std::cout << "----------" << std::endl;

        std::cout << f << std::endl;

    } catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}