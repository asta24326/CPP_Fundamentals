/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/30 18:54:49 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() {
	this->_brain = new Brain;
	this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {

	// so we are passing other's _brain object to copy
	this->_brain = new Brain(*other._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

// Copy assignemt operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operation" << std::endl;
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
Dog::~Dog() {
	delete this->_brain; // deleting created object
	std::cout << "Dog destructor for " << "[" << this << "]" << " called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}