/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:11 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/26 18:00:56 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"
#include <cmath>

// Default constructor
ClapTrap::ClapTrap(const std::string& name) : 
	_name(name), 
	hitPoints(10), 
	energyPoints(10), 
	attackDamage(0) {
	std::cout << "ClapTrap - " << "[" << this->_name << "]" << "constructed!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) : 
	_name(other._name), 
	hitPoints(other.hitPoints), 
	energyPoints(other.energyPoints), 
	attackDamage(other.attackDamage) {
	std::cout << "ClapTrap - " << "[" << this->_name << "]" << " constructor called" << std::endl;
}

// Copy assignment constructor
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap - " << "[" << this->_name << "]" << " copy assignment operatoration - " << std::endl;
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
	std::cout << " ClapTrap - " << "[" << this->_name << "]" << " destructor called" << std::endl;
}

// Methods
void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0) {
		std::cout 
		<< "ClapTrap - " 
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
		std::cout << "ClapTrap - " << "[" << this->_name << "]" << " has 0 energyPoints!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout 
	<< "ClapTrap - " 
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
		<< "ClapTrap - " 
		<< "[" << this->_name << "]"
		<< " gets repaired for "
		<< "[" << amount << "]"
		<< " of points!"
		<< std::endl;

		this->energyPoints--;
		this->hitPoints = this->hitPoints + amount;
	}
	else {
		std::cout << "ClapTrap - " << "[" << this->_name << "]" << " has 0 energyPoints! Stop!" << std::endl;
	}
}

void ClapTrap::printStatus(void) const {
	std::cout << "ClapTrap - [" << _name << "] HP: " << hitPoints 
	          << " | Energy: " << energyPoints 
	          << " | Damage: " << attackDamage << std::endl;
}




