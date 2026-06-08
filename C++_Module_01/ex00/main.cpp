#include <iostream>
#include "Zombie.hpp" // gives us access to the Zombie class and functions

int main(void)
{
	// Allocating a zombie object on the heap
	Zombie *heapZombie = newZombie("The Heap Zombie");
	
	// Utilize zombie object's function to announce itself
	heapZombie->announce();


	// Allocate and automatically destroy a zombie on the stack
	randomChump("The Stack zombie");

	// Deallocate heap memory explicitly to prevent leaks
	delete heapZombie;

	return 0;
}