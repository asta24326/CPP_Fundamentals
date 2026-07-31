/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 10:09:40 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/31 10:10:58 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	std::cout << "=== Ex02: Abstract Class ===" << std::endl;
	
	std::cout << "\n--- Test 1: Cannot instantiate abstract class ---" << std::endl;
	// Animal animal;  // ❌ COMPILE ERROR! 'Animal' is abstract
	std::cout << "✓ Good! Cannot create Animal object (as expected)" << std::endl;
	
	std::cout << "\n--- Test 2: Can create Dog and Cat (concrete classes) ---" << std::endl;
	Dog dog;
	Cat cat;
	std::cout << "✓ Created Dog object" << std::endl;
	std::cout << "✓ Created Cat object" << std::endl;
	
	std::cout << "\n--- Test 3: Polymorphism with abstract class ---" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	
	std::cout << "Calling makeSound() through Animal* pointer:" << std::endl;
	for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();  // Virtual method - each calls correct version
	}
	
	std::cout << "\n--- Test 4: DEEP COPY TEST ---" << std::endl;
	
	Dog originalDog;
	originalDog._brain->ideas[0] = "Original: Chase ball";
	originalDog._brain->ideas[1] = "Original: Eat food";
	
	std::cout << "Original Dog ideas:" << std::endl;
	std::cout << "  ideas[0]: " << originalDog._brain->ideas[0] << std::endl;
	std::cout << "  ideas[1]: " << originalDog._brain->ideas[1] << std::endl;
	std::cout << "  Brain address: " << originalDog._brain << std::endl;
	
	// Copy constructor
	Dog copyDog = originalDog;
	
	std::cout << "\nCopy Dog ideas (before modification):" << std::endl;
	std::cout << "  ideas[0]: " << copyDog._brain->ideas[0] << std::endl;
	std::cout << "  ideas[1]: " << copyDog._brain->ideas[1] << std::endl;
	std::cout << "  Brain address: " << copyDog._brain << std::endl;
	
	// Modify the COPY
	copyDog._brain->ideas[0] = "CHANGED: Different idea";
	copyDog._brain->ideas[1] = "CHANGED: Another idea";
	
	std::cout << "\nAfter modifying COPY (original should NOT change):" << std::endl;
	std::cout << "Original ideas:" << std::endl;
	std::cout << "  ideas[0]: " << originalDog._brain->ideas[0] << std::endl;
	std::cout << "  ideas[1]: " << originalDog._brain->ideas[1] << std::endl;
	
	std::cout << "Copy ideas:" << std::endl;
	std::cout << "  ideas[0]: " << copyDog._brain->ideas[0] << std::endl;
	std::cout << "  ideas[1]: " << copyDog._brain->ideas[1] << std::endl;
	
	// Check if deep copy worked
	if (originalDog._brain->ideas[0] != copyDog._brain->ideas[0]) {
		std::cout << "\n✓ DEEP COPY WORKS! (Original and Copy have different Brain objects)" << std::endl;
	} else {
		std::cout << "\n❌ SHALLOW COPY! (Original and Copy share same Brain - BAD!)" << std::endl;
	}
	
	std::cout << "\n--- Test 5: Virtual Destructor ---" << std::endl;
	std::cout << "Deleting array of Animals (created with new):" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete animals[i];  // Virtual destructor calls Dog::~Dog or Cat::~Cat
	}
	
	std::cout << "\n--- Test 6: Stack objects auto-cleanup ---" << std::endl;
	std::cout << "originalDog and copyDog will be deleted automatically at end of main" << std::endl;
	
	return 0;
}