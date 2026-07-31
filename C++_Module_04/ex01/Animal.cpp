/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/31 20:10:12 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

// Copy assignemt operator
Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assignment operation" << std::endl;
	if (this != &other) {
		this->type = other.type;
		std::cout << "done succesfully!" << std::endl;
	}
	else
		std::cout << "failed due self copying!" << std::endl;
	return *this;
}

// Desctructor
Animal::~Animal() {
	std::cout << "Animal destructor for " << "[" << this << "]" << " called!" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Default sound" << std::endl;
}
