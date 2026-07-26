/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 21:29:57 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/26 17:14:39 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	
	// protected - for inherited object to have access to it
	protected:
		std::string _name;
		int hitPoints;
		int energyPoints;
		int attackDamage;

	public:
		// OCF constructors
		ClapTrap(const std::string& _name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
	
		// Methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Status logging
		void printStatus(void) const;
};

#endif