/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:31:56 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/13 19:31:58 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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