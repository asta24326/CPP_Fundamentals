/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:52:00 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:55:06 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
	private:
		std::string _name;
		Weapon& _weapon;
	
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);

		void attack();
};

#endif