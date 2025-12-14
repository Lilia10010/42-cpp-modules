/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:32:01 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/14 18:41:43 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cstdlib>

PhoneBook::PhoneBook() : count(0), oldContact(0) {}

std::string PhoneBook::truncateField(const std::string &str) const
{
    if(str.length() > 10)
        return str.substr(0, 9) +  ".";
    return str;
}

bool PhoneBook::isValidPhoneNumber(const std::string &str) const
{
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
        {
            std::cout << "Invalid phone number. Use digits only." << std::endl;
            return (false);
        }
    }
    if (str.length() < 3 || str.length() > 15)
    {
        std::cout << "Invalid phone number. [Min 3 digits] [Max 15 digits]" << std::endl;
        return (false);
    }
        
    return (true);
}

bool    PhoneBook::isOnlyWhitespace(const std::string &str) const
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isspace(str[i]))
            return (false);
    }
    return (true);
}

std::string PhoneBook::askAndRead(const std::string &prompt) const
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
       if (!std::getline(std::cin, input))
       {
        std::cout << std::endl;
        std::exit(0);
       }
        
        if (!input.empty() && !isOnlyWhitespace(input))
            return (input);
        
        std::cout << "Field cannot be empty. Try again!" << std::endl;
    }

}

std::string PhoneBook::askAndReadNumber(const std::string &prompt) const
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        if(!std::getline(std::cin, input))
        {
            std::cout << std::endl;
            std::exit(0);
        }

        if (isValidPhoneNumber(input))
            return input;
    }
}

void    PhoneBook::addContact()
{
    Contact newContact;

    newContact.setFirstName(askAndRead("Fist name: "));
    newContact.setLastName(askAndRead("Last name: "));
    newContact.setNickname(askAndRead("Nickname: "));
    newContact.setPhoneNumber(askAndReadNumber("Phone number: "));
    newContact.setDarkestSecret(askAndRead("Darkest secret: "));

    contacts[oldContact] = newContact;
    
    if (count < 8)
        count ++;

    oldContact = (oldContact + 1) % 8;    
    std::cout << "Contact added successfully" << std::endl;

}

void    PhoneBook::printContactTable() const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "|  Index  | First Name | Last Name | Nickname |\n";
    std::cout << "-------------------------------------------------\n";


    for (int i = 0; i < count; ++i)
    {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << truncateField(contacts[i].getFirstName())
                  << "|" << std::setw(10) << truncateField(contacts[i].getLastName())
                  << "|" << std::setw(10) << truncateField(contacts[i].getNickname())
                  << "|" << std::endl;
    }
}

void PhoneBook::printContactDetails(int index) const
{
    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }

    const Contact &c = contacts[index];

    std::cout << "----------------------------------\n";
    std::cout << "        CONTACT DETAILS\n";
    std::cout << "----------------------------------\n";
    std::cout << "First name     : " << c.getFirstName() << "\n";
    std::cout << "Last name      : " << c.getLastName() << "\n";
    std::cout << "Nickname       : " << c.getNickname() << "\n";
    std::cout << "Phone number   : " << c.getPhoneNumber() << "\n";
    std::cout << "Darkest secret : " << c.getDarkestSecret() << "\n";
    std::cout << "----------------------------------\n";
}

void PhoneBook::searchContacts() const
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty!" << std::endl;
        return ;
    }

    printContactTable();

    std::string input;
    int index;

    std::cout << "Enter the index: " << std::endl;
    if(!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        std::exit(0);
    }

    std::istringstream iss(input);
    iss >> index;

    if (iss.fail())
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }

    printContactDetails(index);
}