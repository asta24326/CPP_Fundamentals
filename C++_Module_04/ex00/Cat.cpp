/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/27 21:57:25 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() {
	this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignemt operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operation" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		std::cout << "done succesfully!" << std::endl;
	}
	else
		std::cout << "failed due self copying!" << std::endl;
	return *this;
}

// Desctructor
Cat::~Cat() {
	std::cout << "Cat destructor for " << "[" << this << "]" << " called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}