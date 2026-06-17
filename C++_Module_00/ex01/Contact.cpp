/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:50:19 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:53:40 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

// Constructor
Contact::Contact() {
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

// Desctructor
Contact::~Contact() {
	// no dynamic memory allocated, that's why no clean up needed
}

// Public Setter Function
// This allow the Phonebook to assign all 5 data fields at once.
void Contact::setInfo(
	const std::string& first, const std::string& last,
	const std::string& nick, const std::string& phone,
	const std::string& secret) {
	_firstName = first;
	_lastName = last;
	_nickname = nick;
	_phoneNumber = phone;
	_darkestSecret = secret;
}

// Public Getter function
// The 'const' suffix matches our header declarations and read-only access
std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getNickname() const {
	return _nickname;
}

std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}