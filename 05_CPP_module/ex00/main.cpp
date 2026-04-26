/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:49:13 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 12:25:35 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat a("Mariazinha", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.incrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 151); //
    }
    catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}