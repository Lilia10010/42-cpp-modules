/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:32:43 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/13 22:27:52 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact();

        void setFirstName(const std::string &value);
        void setLastName(const std::string &value);
        void setNickname(const std::string &value);
        void setPhoneNumber(const std::string &value);
        void setDarkestSecret(const std::string &value);

        const std::string &getFirstName() const;
        const std::string &getLastName() const;
        const std::string &getNickname() const;
        const std::string &getPhoneNumber() const;
        const std::string &getDarkestSecret() const;
};

#endif