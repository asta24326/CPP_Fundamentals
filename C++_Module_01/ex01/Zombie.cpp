/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:51:38 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:54:46 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

// Constructor default
Zombie::Zombie() : _name("") {}

// Constructor parameterized
Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie() {
	std::cout << this->_name << ": has been utterly destroyed." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	this->_name = name;
}