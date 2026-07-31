/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/30 18:42:45 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Default constructor
Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other) {
	
	int i = 0;
	while (i < 100) {
		this->ideas[i] = other.ideas[i];
		i++;
	}
    std::cout << "Brain copy constructor called" << std::endl;
}

// Copy assignemt operator
Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignment operation" << std::endl;
	if (this != &other) {
		int i = 0;
		while (i < 100) {
			this->ideas[i] = other.ideas[i];
			i++;
		}
		std::cout << "done succesfully!" << std::endl;
	}
	else
		std::cout << "failed due self copying!" << std::endl;
	return *this;
}

// Desctructor
Brain::~Brain() {
	std::cout << "Brain destructor for " << "[" << this << "]" << " called!" << std::endl;
}