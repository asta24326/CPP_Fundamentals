/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/28 22:41:04 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() {
	this->type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copy constructor called" << std::endl;
}

// Copy assignemt operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat copy assignment operation" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
		std::cout << "done succesfully!" << std::endl;
	}
	else
		std::cout << "failed due self copying!" << std::endl;
	return *this;
}

// Desctructor
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor for " << "[" << this << "]" << " called!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}