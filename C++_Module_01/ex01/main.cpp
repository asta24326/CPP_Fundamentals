#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
	Zombie* myHorde = zombieHorde(5, "I'm Zombie");

	for(int i = 0; i < 5; i++) {
		myHorde[i].announce();
	}
	delete[] myHorde;
	return 0;
}