/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:46:49 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/26 17:07:50 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main(void) {
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap a("Bot-1");
	a.printStatus();
	
	std::cout << "\n=== Testing attack ===" << std::endl;
	a.attack("Enemy");
	a.printStatus();
	a.attack("Enemy");
	a.printStatus();
	
	std::cout << "\n=== Testing takeDamage ===" << std::endl;
	a.takeDamage(3);
	a.printStatus();
	
	std::cout << "\n=== Testing beRepaired ===" << std::endl;
	a.beRepaired(2);
	a.printStatus();
	
	std::cout << "\n=== Attacking until energy is over ===" << std::endl;
	for (int i = 0; i < 12; i++) {
		a.attack("Target");
		a.printStatus();
	}
	
	std::cout << "\n=== Copy constructor of 'b' called ===" << std::endl;
	ClapTrap b(a);
	b.printStatus();
	
	std::cout << "\n=== Copy assignment ===" << std::endl;
	ClapTrap c("Bot-2");
	c.printStatus();
	std::cout << "Assigning a to c..." << std::endl;
	c = a;
	c.printStatus();
	
	// std::cout << "\n=== Self-assignment ===" << std::endl;
	// a = a;
	// a.printStatus();
	
	std::cout << "\n=== End of main ===" << std::endl;
	return 0;
}