#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	std::cout << "===== TESTING FRAGTRAP =====" << std::endl;
	FragTrap f("FragBot");
	f.printStatus();
	
	std::cout << "\n--- FragTrap attack (30 damage) ---" << std::endl;
	f.attack("Enemy");
	f.printStatus();
	
	std::cout << "\n--- FragTrap takeDamage ---" << std::endl;
	f.takeDamage(15);
	f.printStatus();
	
	std::cout << "\n--- FragTrap beRepaired ---" << std::endl;
	f.beRepaired(10);
	f.printStatus();
	
	std::cout << "\n--- FragTrap highFivesGuys ---" << std::endl;
	f.highFivesGuys();
	
	std::cout << "\n===== COMPARE ALL THREE =====" << std::endl;
	ClapTrap c("ClapBot");
	ScavTrap s("ScavBot");
	FragTrap f2("FragBot");
	
	std::cout << "ClapTrap:" << std::endl;
	c.printStatus();
	std::cout << "ScavTrap:" << std::endl;
	s.printStatus();
	std::cout << "FragTrap:" << std::endl;
	f2.printStatus();
	
	std::cout << "\n===== END =====" << std::endl;
	return 0;
}