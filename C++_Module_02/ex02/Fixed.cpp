/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed02.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 10:46:11 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/24 19:58:15 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <cmath>

//////////
// Constructors
//////////

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


//////////
// Operators - comparison
//////////

bool Fixed::operator==(const Fixed& other) const {
	return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_rawBits != other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_rawBits < other._rawBits;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->_rawBits > other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_rawBits <= other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_rawBits >= other._rawBits;
}


//////////
// Operators - math
//////////

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawBits * other._rawBits) >> _fractionalBits);
	return result;
}
		// Example: Fixed(5) * Fixed(2) = Fixed(10)
		// this->_rawBits = 5 * 256 = 1280
		// other._rawBits = 2 * 256 = 512
		// 1280 * 512 = 655360
		// 655360 >> 8 (dividing by 256) = 2560
		// 2560 / 256 = 10 ✓


Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawBits << 8) / other._rawBits);
	return result;
}
		// Example: Fixed(10) / Fixed(2) = Fixed(5)
		// this->_rawBits = 10 * 256 = 2560
		// other._rawBits = 2 * 256 = 512
		//
		// if 2560/512 = 5(in raw bits) X
		//
		// 2560 << 8 (multiply by 256) = 655360
		// 655360 / 512 = 1280 (rawBits)
		// 1280 / 256 = 5 ✓


//////////
// Operators - increments
//////////

Fixed& Fixed::operator++(){
	this->_rawBits++;
	return *this;
}

Fixed& Fixed::operator--(){
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this; // creating a temporary object on stack memory

	this->_rawBits++;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;

	this->_rawBits--;
	return temp;
}


//////////
// Operators - min max
//////////

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a._rawBits < b._rawBits)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a._rawBits > b._rawBits)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed&b) {
	if (a._rawBits < b._rawBits)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed&b) {
	if (a._rawBits > b._rawBits)
		return a;
	else
		return b;
}

//////////
// Methods
//////////

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