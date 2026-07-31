/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/31 20:44:18 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() {
	this->_brain = new Brain;
	this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other) {

	// so we are passing other's _brain object to copy
	this->_brain = new Brain(*other._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignemt operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operation" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete this->_brain;	// deleting currently existing brain inside our object
		this->_brain = new Brain(*other._brain);
		std::cout << "done succesfully!" << std::endl;
	}
	else
		std::cout << "failed due self copying!" << std::endl;
	return *this;
}

// Desctructor
Cat::~Cat() {
	delete this->_brain; // deleting created object
	std::cout << "Cat destructor for " << "[" << this << "]" << " called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}