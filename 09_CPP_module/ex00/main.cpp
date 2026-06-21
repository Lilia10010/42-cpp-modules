/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:42:47 by microbiana        #+#    #+#             */
/*   Updated: 2026/06/21 12:42:47 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.processInputFile(argv[1]);
	}
	catch (const BitcoinExchange::FileOpenException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
