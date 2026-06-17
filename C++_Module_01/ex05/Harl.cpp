/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:17:02 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:55:44 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() const {
	std::cout 
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void Harl::info() const {
	std::cout 
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void Harl::warning() const {
	std::cout 
		<< "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void Harl::error() const {
	std::cout 
		<< "Th is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

// creating array with pointers to functions that belong to class Harl
void Harl::complain(std::string level) {
	void (Harl::*functions[])() const = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			(this->*functions[i])();
	}
}
