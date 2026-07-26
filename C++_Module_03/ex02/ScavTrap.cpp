/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:11 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/26 18:21:50 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap method - " << "[" << this->_name << "]" << " constructed!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap method - " << "[" << this->_name << "]" << " constructor called" << std::endl;
}

// Copy assignment constructor
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap method - " << "[" << this->_name << "]" << " copy assignment operatoration - " << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "done succesfully!" << std::endl;
	} else {
		std::cout << "failed due self copying!" << std::endl;
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << " ScavTrap method - name: " << "[" << this->_name << "]" << "  with address: [" << this << "]" << std::endl;
}

// Methods
void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap method - " << "[" << _name << "]" << " is now in gate keeper mode!" << std::endl;
}

// changed messages for ScavTrap specifically
void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints > 0) {
		std::cout 
		<< "ScavTrap method - " 
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
		std::cout << "ScavTrap method - " << "[" << this->_name << "]" << " has 0 energyPoints!" << std::endl;
	}
}

// Methods takeDamage and beRepaired - stays inheritated

void ScavTrap::printStatus(void) const {
	std::cout << "   status: " << "ScavTrap method - " << "[" << _name << "] HP: " << hitPoints 
	          << " | Energy: " << energyPoints 
	          << " | Damage: " << attackDamage << std::endl;
}






