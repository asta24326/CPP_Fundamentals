/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:51:42 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:54:50 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();					// default constructor with no arguments and parameters (for new[])
		Zombie(const std::string& name);	// constructor with parameters
		~Zombie();
		void announce();
		void setName(const std::string& name);
};


#endif