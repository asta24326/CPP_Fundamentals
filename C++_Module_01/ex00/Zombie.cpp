/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:51:14 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:54:34 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"
// 1. Constructor: Initializes the private attribute '_name'
// intentional blank body if no further initialization setup is required

Zombie::Zombie(std::string name) : _name(name) {
}

// 2. Desctructor' Automatically invoked upon object desctruction
// It must print a message sidplaying the zombie's name

Zombie::~Zombie() {
	std::cout << this->_name << ": has been utterly destroyed." << std::endl;
}

// 3. The Announce Member function: outputs the required dialogue to standard output
// by subject name is is "BraiiiiiiiinnnzzzZ..." << std::endl;

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}