#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	private:
		// Encapsualted data members (Attributes)
		// _ before variable name is designated for objects variable names
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact(void);	// Constructor

		~Contact(void);	// Destructor

		// Public member functions to populate data (Setters)
		void setInfo(
			const std::string& first,
			const std::string& last,
			const std::string& nick,
			const std::string& phone,
			const std::string& secret);

		// Public member functions to retrieve data (Getters)
		std::string getFirstName(void) const; // const - means that it's read-only function
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
};

#endif