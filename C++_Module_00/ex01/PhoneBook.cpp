/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:50:48 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/14 20:46:17 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip> // Required for strd::setw(set width) and std::right(for right alignment)
#include <string>
#include <sstream> // For safe string-to-int conversion
#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook(void) {
	_contactCount = 0;
}

//Destructor
PhoneBook::~PhoneBook(void) {
	// empty because of stack allocation
}

// Helper function to format strings to fit exactly 10 columns
std::string formatColumn(std::string str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + "."; // substring from index 0, taking exactly 9 chars, then append '.'
	}
	return str;
}

// Main ADD contact logic
void PhoneBook::addContact(void) {
	std::string first, last, nick, phone, secret;

	std::cout << "\n---> Adding a New Contact" << std::endl;

	// Entering First Name
	while (true) {
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, first)) // Ctrl+D protection
			return ;
		if (!first.empty())
			break;
		std::cout << "Field cannot be empty. Try again!\n";
	}

	// Entering Last Name
	while (true) {
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, last)) // Ctrl+D protection
			return ;
		if (!last.empty())
			break;
		std::cout << "Field cannot be empty. Try again!\n";
	}

	// Entering Nickname
	while (true) {
		std::cout << "Enter Nickname: ";
		if (!std::getline(std::cin, nick)) // Ctrl+D protection
			return ;
		if (!nick.empty())
			break;
		std::cout << "Field cannot be empty. Try again!\n";
	}

	// Entering Phone number
	while (true) {
		std::cout << "Enter Phone number: ";
		if (!std::getline(std::cin, phone)) // Ctrl+D protection
			return ;
		if (phone.empty()) {
			std::cout << "Field cannot be empty. Try again!\n";
			continue;
		}

		// Check for digits
		bool isDigits = true;
		for (size_t i = 0; i < phone.length(); i++) {
			if (!std::isdigit(phone[i])) {
				isDigits = false;
				break;
			}
		}

		// check if digit check passed
		if (isDigits) {
			break; // Success
		}
		std::cout << "Invalid format! Numbers only. Try again!\n";
	}

	// Entering Phone number
	while (true) {
		std::cout << "Enter Darkest secret: ";
		if (!std::getline(std::cin, secret)) // Ctrl+D protection
			return ;
		if (!secret.empty())
			break;
		std::cout << "Field cannot be empty. Try again!\n";
	}

	// Calculate target array slot safely using module math
	int targetIndex = _contactCount % 8;
	_contacts[targetIndex].setInfo(first, last, nick, phone, secret);
	_contactCount++;

	// Success message
	std::cout << "Contact sucessfully saved at slot [" << (targetIndex + 1) << "]!\n";
}

void PhoneBook::searchContact(void) const {

	// 0. Determine how many slots are actually filled with contacts (max is 8)
	int limit = (_contactCount > 8) ? 8 : _contactCount;

	if (limit == 0) {
		std::cout << "\nPhonebook is completely empty!" << std::endl;
		return;
	}
	// 1. Print the Table Header
	std::cout << "|" << std::setw(10) << std::right << "Index"
				<< "|" << std::setw(10) << std::right << "First Name"
				<< "|" << std::setw(10) << std::right << "Last Name"
				<< "|" << std::setw(10) << std::right << "Nickname"
				<< "|" << std::endl;

	// 2. Loop and print each filled Contact row
	for (int i = 0; i < limit; i++)	{
		std::cout << "|" << std::setw(10) << std::right << (i + 1) // Display 1 - indexed for the user
					<< "|" << std::setw(10) << std::right << formatColumn(_contacts[i].getFirstName())
					<< "|" << std::setw(10) << std::right << formatColumn(_contacts[i].getLastName()) 
					<< "|" << std::setw(10) << std::right << formatColumn(_contacts[i].getNickname())
					<< "|" << std::endl;
	}

	// 3. Prompt user for an index to see complete details
	std::string input;
	std::cout << "\nEnter the index of the contact to display: ";
	if (!std::getline(std::cin, input)) {
		return;
	}
	if (input.empty()) {
		std::cout << "Error: Index cannot be empty!" << std::endl;
		return;
	}

	// Verify the input contains only numberic digits
	for(size_t j = 0; j < input.length(); j++) {
		if (!std::isdigit(input[j])) {
			std::cout << "Error: Invalid index format (numbers only)!" << std::endl;
			return;
		}
	}

	// Convert input string safely via stringstream
	std::stringstream ss(input);
	int chosenIndex;
	ss >> chosenIndex;

	if (chosenIndex < 1 || chosenIndex > limit) {
		std::cout << "Error: Index out of range or contact does not exist." << std::endl;
		return;
	}

	// Convert 1-based user input back to 0-base array lookup index
	int targetSlot = chosenIndex - 1;
	std::cout << "\nFirst Name: " << _contacts[targetSlot].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[targetSlot].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[targetSlot].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[targetSlot].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[targetSlot].getDarkestSecret() << std::endl;
}