#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
        int oldContact;

    public:
        PhoneBook();

        void addContact();
        void searchContacts() const;
        void printContactTable() const;
        void printContactDetails(int index) const;

    private:
        std::string truncateField(const std::string &std) const;
        std::string askAndRead(const std::string &prompt) const;
};

#endif