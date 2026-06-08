#include "Zombie.hpp"

void randomChump(std::string name) {

	// Allocate a Zombie object entirely on the stack.
	// Memory is managed automatically within this function's scope.

	Zombie stackZombie(name);

	// Instruct the stack-allocated zombie to execute it's member function

	stackZombie.announce();

} // Scope closes here: stackZombie is implicitly destroyed, invoking the destructor