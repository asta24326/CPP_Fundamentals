/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:52:10 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:55:13 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;
	
	public:
		HumanB(const std::string& name);
		~HumanB(void);

		void setWeapon(Weapon& weapon);
		void attack();
};

#endif