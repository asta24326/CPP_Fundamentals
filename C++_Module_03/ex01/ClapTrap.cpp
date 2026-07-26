/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:11 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/26 18:22:27 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(const std::string& name) : 
	_name(name), 
	hitPoints(10), 
	energyPoints(10), 
	attackDamage(0) {
	std::cout << "ClapTrap method - " << "[" << this->_name << "]" << " constructed!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : 
	_name(other._name), 
	hitPoints(other.hitPoints), 
	energyPoints(other.energyPoints), 
	attackDamage(other.attackDamage) {
	std::cout << "ClapTrap method - " << "[" << this->_name << "]" << " constructor called" << std::endl;
}

// Copy assignment constructor
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap method - " << "[" << this->_name << "]" << " copy assignment operatoration - " << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		std::cout << "done succesfully!" << std::endl;
	} else {
		std::cout << "failed due self copying!" << std::endl;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << " ClapTrap method - name: " << "[" << this->_name << "]" << "  with address: [" << this << "]" << std::endl;
}

// Methods
void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0) {
		std::cout 
		<< "ClapTrap method - " 
		<< "[" << this->_name << "]"
		<< " attacks "
		<< "[" << target << "]"
		<< ", causing "
		<< "[" << this->attackDamage << "]"
		<< " points of damage!"
		<< std::endl;
		this->energyPoints--;
	}
	else {
		std::cout << "ClapTrap method - " << "[" << this->_name << "]" << " has 0 energyPoints!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout 
	<< "ClapTrap method - " 
	<< "[" << this->_name << "]"
	<< " took "
	<< "[" << amount << "]"
	<< " of damage!"
	<< std::endl;

	this->hitPoints = this->hitPoints - amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0) {
		std::cout 
		<< "ClapTrap method - " 
		<< "[" << this->_name << "]"
		<< " gets repaired for "
		<< "[" << amount << "]"
		<< " of points!"
		<< std::endl;

		this->energyPoints--;
		this->hitPoints = this->hitPoints + amount;
	}
	else {
		std::cout << "ClapTrap method - " << "[" << this->_name << "]" << " has 0 energyPoints! Stop!" << std::endl;
	}
}

void ClapTrap::printStatus(void) const {
	std::cout << "   status: " << "ClapTrap method - [" << _name << "] HP: " << hitPoints 
	          << " | Energy: " << energyPoints 
	          << " | Damage: " << attackDamage << std::endl;
}




