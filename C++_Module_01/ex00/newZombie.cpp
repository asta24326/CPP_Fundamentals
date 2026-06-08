#include "Zombie.hpp"

Zombie* newZombie(std::string name) {

	// Dynamically allocate a Zombie object on the hep using the 'new' operator
	// This simultaneously allocates memory and invokes the constructor

	Zombie* allocatedZombie = new Zombie(name);

	// Return the memory address of the newly created object
	return allocatedZombie;
}
