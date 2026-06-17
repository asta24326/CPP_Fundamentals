/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:11 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 12:16:58 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _rawBits (0) {
	std::cout << "Default constructor called" << std::endl;
}

// Constructor int → fixed-point
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << _fractionalBits;
}

// Constructor float → fixed-point  
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(value * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // calling copy assignment operator
}

// Copy assignment constructor
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;	
}

float Fixed::toFloat() const {
	float result;
	result = (float)_rawBits / (1 << _fractionalBits);
    return result; 
}

int Fixed::toInt(void) const {
	int result;
	result = _rawBits >> _fractionalBits;
    return result;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// 
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}