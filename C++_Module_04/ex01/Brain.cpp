/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 20:57:53 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/31 20:19:20 by aidarsharaf      ###   ########.fr       */
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

// Setter
void Brain::setIdea(int idx, std::string idea) {
	this->ideas[idx] = idea;
	std::cout << "Brain setter - succesfully!" << std::endl;
}

// Getter
std::string Brain::getIdea(int idx) const {
	std::cout << "Brain getter returned - succesfully!" << std::endl;
	return this->ideas[idx];
}