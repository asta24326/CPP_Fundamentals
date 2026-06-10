#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(void);					// default constructor with no arguments and parameters (for new[])
		Zombie(const std::string& name);	// constructor with parameters
		~Zombie();
		void announce(void);
		void setName(const std::string& name);
};


#endif