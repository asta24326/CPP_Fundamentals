/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 21:29:57 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 12:07:53 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 private:
	int _rawBits;
	static const int _fractionalBits = 8;

 public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int   toInt(void) const;

};

// Out of class operator over-write
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
/* 

	Useful info:

	// 1. Const parameter — cannot modify the parameter inside the function:
		void setRawBits(int const raw);

	// 2. Const reference — cannot modify the object through the reference:
		void foo(const Fixed& other);

	// 3. Const method — cannot modify the object's attributes:
		int getRawBits(void) const;
*/