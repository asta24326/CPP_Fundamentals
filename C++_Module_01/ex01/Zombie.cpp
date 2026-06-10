#include "Zombie.hpp"

// Constructor default
Zombie::Zombie(void) {}

// Constructor parameterized
Zombie::Zombie(const std::string& name) : _name(name) {}

Zombie::~Zombie(void) {
	std::cout << this->_name << ": has been utterly destroyed." << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name) {
	this->_name = name;
}