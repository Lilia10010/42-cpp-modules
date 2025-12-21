/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:47:53 by microbiana        #+#    #+#             */
/*   Updated: 2025/12/21 18:39:32 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplo-picles-ketchup-especial. Eu realmente amo!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Eu não acredito que adicionar bacon extra custa mais dinheiro. Vocês não colocaram bacon suficiente no meu hambúrguer!"
    << "Se vocês tivessem colocado, eu não estaria pedindo por mais!" << std:: endl;
}

void Harl::warning(void)
{
    std::cout << "Eu acho que mereço ter bacon extra de graça. Eu venho aqui há anos, enquanto você começou a trabalhar aqui apenas no mês passado." << std::endl;
}

void Harl::error(void)
{
    std::cout << "Isto é inaceitável! Eu quero falar com o gerente agora." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = 
    {
        "DEBUG", "INFO", "WARNING", "ERROR"
    };

    //ponteiro para uma função da classe Harl, passando o endereço da função membro para cada posição
    void (Harl::*functions[4])(void) = 
    {
        &Harl::debug, &Harl::info,  &Harl::warning, &Harl::error
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            std::cout << std::endl;
            return ;
        }
    }

    std::cout << "Nível de reclaamação inválido" << std::endl;
}

