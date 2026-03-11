/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:32:12 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/14 18:42:30 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int  main()
{
    PhoneBook book;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, command))
            break ;

        if (command == "ADD")
            book.addContact();
        else if (command == "SEARCH")
            book.searchContacts();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Invalid command. Try again! " << std::endl;
    }

    return (0);
}