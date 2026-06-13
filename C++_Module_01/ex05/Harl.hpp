/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:13:54 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/13 22:40:42 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;

	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);	
};

#endif