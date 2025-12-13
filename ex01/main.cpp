#include "PhoneBook.hpp"
#include <iostream>

int  main()
{
    PhoneBook book;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

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