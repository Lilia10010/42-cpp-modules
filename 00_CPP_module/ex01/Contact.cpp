/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:32:48 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/13 19:32:49 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

void Contact::setFirstName(const std::string &value)		{ firstName = value; }
void Contact::setLastName(const std::string &value)			{ lastName = value; }
void Contact::setNickname(const std::string &value)			{ nickname = value; }
void Contact::setPhoneNumber(const std::string &value)		{ phoneNumber = value; }
void Contact::setDarkestSecret(const std::string &value)	{ darkestSecret = value; }

const std::string &Contact::getFirstName() const		{ return firstName; }
const std::string &Contact::getLastName() const			{ return lastName; }
const std::string &Contact::getNickname() const			{ return nickname; }
const std::string &Contact::getPhoneNumber() const		{ return phoneNumber; }
const std::string &Contact::getDarkestSecret() const	{ return darkestSecret; }
