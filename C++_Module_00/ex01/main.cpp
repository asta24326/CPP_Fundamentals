#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook		book; // initializing on stack
	std::string		command;

	std::cout << "--- Welcome to My Awesome PhoneBook ---" << std::endl;
	std::cout << "\nAvailable commands: ADD, SEARCH, EXIT" << std::endl;

	// The stream evaluates to false automatically if Ctrl+D is encountered
	std::cout << "\nEnter command > ";

	// Main reading loop
	while (std::getline(std::cin, command)) {

		if (command == "ADD")
			book.addContact();
		else if	(command == "SEARCH")
			book.searchContact();
		else if (command == "EXIT") {
			std::cout << "\n\nExiting PhoneBook. Ciao!" << std::endl;
			break;
		}
		else {
			if (!command.empty()) {
				std::cout << "Invalid command! Please use ADD, SEARCH or EXIT!" << std::endl;
			}
		}
		std::cout << "\nEnter command > ";
	}

	// Checking if the loop exited specifically because the input stream collapsed
	if (std::cin.eof()) {
		std::cout << "\nEOF detected. Exiting safely!" << std::endl;
	}

	return 0;
}
