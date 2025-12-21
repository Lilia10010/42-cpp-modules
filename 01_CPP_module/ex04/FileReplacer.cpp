/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:31:34 by microbiana        #+#    #+#             */
/*   Updated: 2025/12/21 15:11:48 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(const std::string &file,
                         const std::string &search,
                         const std::string &replace)
    : inputFile(file), s1(search), s2(replace) {}

std::string FileReplacer::replaceContent(const std::string &content)
{
    std::string result;
    size_t      currentPosition = 0;
    size_t      found;

    while ((found = content.find(s1, currentPosition)) != std::string::npos)
    {        
        result.append(content.substr(currentPosition, found - currentPosition));        
        result.append(s2);        
        currentPosition = found + s1.length();
    }

    result.append(content.substr(currentPosition));
    return (result);
}

bool FileReplacer::process()
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 connot be empty" << std::endl;
        return (false);
    }
    //abrir arquivo de entrada
    std::ifstream inFile(inputFile.c_str());
    if (!inFile)
    {
        std::cerr << "Error: could not open input file" << std::endl;
        return (false);
    }
    //criaar o arquivo de saida
    std::ofstream outFile((inputFile + ".replace").c_str());
    if (!outFile)
    {
        std::cerr << "Error: could not  create output file" << std::endl;
        return (false);
    }
    std::string line;
    while (std::getline(inFile, line))
    {
        outFile << replaceContent(line);

        if(!inFile.eof())
            outFile << std::endl;
    }
    return (true);
}
