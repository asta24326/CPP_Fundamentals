/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:11 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/26 18:40:10 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap method - " << "[" << this->_name << "]" << " constructed!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap method - " << "[" << this->_name << "]" << " constructor called" << std::endl;
}

// Copy assignment constructor
FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap method - " << "[" << this->_name << "]" << " copy assignment operatoration - " << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "done succesfully!" << std::endl;
	} else {
		std::cout << "failed due self copying!" << std::endl;
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << " FragTrap method - name: " << "[" << this->_name << "]" << "  with address: [" << this << "]" << std::endl;
}

// Methods
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap method - " << "[" << _name << "]" << " give me high five!" << std::endl;
}

// changed messages for ScavTrap specifically
void FragTrap::attack(const std::string& target) {
	if (this->energyPoints > 0) {
		std::cout 
		<< "FragTrap method - " 
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
		std::cout << "FragTrap method - " << "[" << this->_name << "]" << " has 0 energyPoints!" << std::endl;
	}
}

// Methods takeDamage and beRepaired - stays inheritated

void FragTrap::printStatus(void) const {
	std::cout << "   status: " << "FragTrap method - " << "[" << _name << "] HP: " << hitPoints 
	          << " | Energy: " << energyPoints 
	          << " | Damage: " << attackDamage << std::endl;
}






