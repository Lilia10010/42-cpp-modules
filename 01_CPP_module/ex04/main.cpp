/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:31:47 by microbiana        #+#    #+#             */
/*   Updated: 2025/12/21 15:05:19 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: <./replace> <file> <s1> <s2>" << std::endl;
        return (1);
    }

    FileReplacer replacer(argv[1], argv[2], argv[3]);

    if (!replacer.process())
        return (1);

    return (0);
}