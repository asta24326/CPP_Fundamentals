/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/27 21:57:39 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Copy assignemt operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy assignment operation" << std::endl;
	if (this != &other) {
		this->type = other.type;
		std::cout << "done succesfully!" << std::endl;
	}
	else
		std::cout << "failed due self copying!" << std::endl;
	return *this;
}

// Desctructor
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor for " << "[" << this << "]" << " called!" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong default sound" << std::endl;
}
