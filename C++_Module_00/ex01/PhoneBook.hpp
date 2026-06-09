#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];	// Fixed array of exactly 8 contacts on the stack
		int		_contactCount;	// Tracks total contacts added (can exceed 8)

	public:
		PhoneBook(void);	// Constructor
		~PhoneBook(void);	// Desctructor

		// Public interface to process core user commands
		void addContact(void);
		void searchContact(void) const;
};

#endif