/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:32:01 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/13 19:32:02 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : count(0), oldContact(0) {}

std::string PhoneBook::truncateField(const std::string &str) const
{
    if(str.length() > 10)
        return str.substr(0, 9) +  ".";
    return str;
}

std::string PhoneBook::askAndRead(const std::string &prompt) const
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (!input.empty())
            return input;
        
        std::cout << "Field cannot be empty. Try again!" << std::endl;
    }

}

void    PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    newContact.setFirstName(askAndRead("Fist name: "));
    newContact.setLastName(askAndRead("Last name: "));
    newContact.setNickname(askAndRead("Nickname: "));
    newContact.setPhoneNumber(askAndRead("Phone number: "));
    newContact.setDarkestSecret(askAndRead("Darkest secret: "));

    int indexContact = (count < 8 ? count : oldContact);
    contacts[indexContact] = newContact;

    if (count < 8)
        count ++;
    else
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
    std::getline(std::cin, input);

    //istringstream permite tratar uma string como fluxo
    //Convertemos de forma controlada
    std::istringstream iss(input);
    iss >> index;

    if (iss.fail())
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }

    printContactDetails(index);
}