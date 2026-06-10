#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "Negative or zero amount of Zombies!" << std::endl;
		return (NULL);
	}
	Zombie* horde = new Zombie[N]; // declaring Zombie array
	for (int i = 0; i < N; i++) {
		std::stringstream ss;
		ss << name;
		ss << "_";
		ss << i;
		horde[i].setName(ss.str());
	}
	return (horde);
}