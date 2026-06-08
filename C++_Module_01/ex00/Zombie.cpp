// cpp file plays the role of Defining of the class's constructior, destructor and methods

#include "Zombie.hpp"


// 1. Constructor: Initializes the private attribute '_name'
// intentional blank body if no further initialization setup is required

Zombie::Zombie(std::string name) : _name(name) {

}




// 2. Desctructor' Automatically invoked upon object desctruction
// It must print a message sidplaying the zombie's name

Zombie::~Zombie(void) {
	std::cout << this->_name << ": has been utterly destroyed." << std::endl;
}

// 3. The Announce Member function: outputs the required dialogue to standard output
// by subject name is is "BraiiiiiiiinnnzzzZ..." << std::endl;

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}
