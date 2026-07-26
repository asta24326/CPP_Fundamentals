#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	std::cout << "===== TESTING CLAPTRAP =====" << std::endl;
	ClapTrap c("ClapBot");
	c.printStatus();
	
	std::cout << "\n===== TESTING SCAVTRAP =====" << std::endl;
	ScavTrap s("ScavBot");
	s.printStatus();
	
	std::cout << "\n--- ScavTrap attack (different damage than ClapTrap) ---" << std::endl;
	s.attack("Enemy");
	s.printStatus();
	s.attack("Enemy");
	s.printStatus();
	
	std::cout << "\n--- ScavTrap takeDamage (inherited method) ---" << std::endl;
	s.takeDamage(10);
	s.printStatus();
	
	std::cout << "\n--- ScavTrap beRepaired (inherited method) ---" << std::endl;
	s.beRepaired(5);
	s.printStatus();
	
	std::cout << "\n--- ScavTrap guardGate (new method) ---" << std::endl;
	s.guardGate();
	
	std::cout << "\n--- Attacking until energy depletes ---" << std::endl;
	for (int i = 0; i < 52; i++) {
		s.attack("Target");
		s.printStatus();
	}
	
	std::cout << "\n--- Try to repair with no energy ---" << std::endl;
	s.beRepaired(10);
	s.printStatus();
	
	std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;
	ScavTrap s2(s);
	s2.printStatus();
	
	std::cout << "\n===== COPY ASSIGNMENT =====" << std::endl;
	ScavTrap s3("ScavBot-3");
	s3.printStatus();
	std::cout << "Assigning s to s3..." << std::endl;
	s3 = s;
	s3.printStatus();
	
	// std::cout << "\n===== SELF-ASSIGNMENT =====" << std::endl;
	// s = s;
	// s.printStatus();
	
	std::cout << "\n===== COMPARE CLAPTRAP vs SCAVTRAP =====" << std::endl;
	std::cout << "ClapTrap:" << std::endl;
	c.printStatus();
	std::cout << "ScavTrap:" << std::endl;
	s.printStatus();
	
	std::cout << "\n===== END OF PROGRAM =====" << std::endl;
	return 0;
}