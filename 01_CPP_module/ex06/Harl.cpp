/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:47:53 by microbiana        #+#    #+#             */
/*   Updated: 2025/12/21 20:52:42 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplo-picles-ketchup-especial. Eu realmente amo! \n\n";
}

void Harl::info(void)
{
     std::cout << "[ INFO ]" << std::endl;
    std::cout << "Eu não acredito que adicionar bacon extra custa mais dinheiro. Vocês não colocaram bacon suficiente no meu hambúrguer!"
    << "Se vocês tivessem colocado, eu não estaria pedindo por mais! \n\n";
}

void Harl::warning(void)
{
     std::cout << "[ WARNING ]" << std::endl;
    std::cout << "Eu acho que mereço ter bacon extra de graça. Eu venho aqui há anos, enquanto você começou a trabalhar aqui apenas no mês passado. \n\n";
}

void Harl::error(void)
{
     std::cout << "[ ERROR ]" << std::endl;
    std::cout << "Isto é inaceitável! Eu quero falar com o gerente agora. \n\n";
}

void Harl::complain(std::string level)
{
    int levelIndex = -1;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
           std::cout << "[ Provavelmente reclamando sobre problemas insignificantes ]" << std::endl;
    }

}

