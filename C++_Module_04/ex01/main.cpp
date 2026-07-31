/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:36:33 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/31 20:36:18 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== With Virtual (Correct Polymorphism) ===" << std::endl;
	
	// Create array of Animal pointers - can hold Dog and Cat
	Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

	std::cout << "\n--- Making sounds (each animal sounds correctly) ---" << std::endl;
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();  // Virtual method - calls correct version
    }

	std::cout << "\n--- DEEP COPY TEST (copy constructor) ---" << std::endl;
    
    // Create original dog
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original: Chase ball");
    originalDog.getBrain()->setIdea(1, "Original: Eat food");

    std::cout << "Original Dog ideas:" << std::endl;
    std::cout << "  ideas[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "  ideas[1]: " << originalDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "  Original Brain address: " << originalDog.getBrain() << std::endl;

    // Copy constructor - should create DEEP copy
    Dog copyDog = originalDog;
    
    std::cout << "\nCopy Dog ideas (before modification):" << std::endl;
    std::cout << "  ideas[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "  ideas[1]: " << copyDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "  Copy Brain address: " << copyDog.getBrain() << std::endl;

    // KEY TEST: Modify the COPY
    copyDog.getBrain()->setIdea(0, "CHANGED: Different idea");
    copyDog.getBrain()->setIdea(1, "CHANGED: Another idea");

    std::cout << "\nAfter modifying COPY (original should NOT change):" << std::endl;
    std::cout << "Original ideas:" << std::endl;
    std::cout << "  ideas[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "  ideas[1]: " << originalDog.getBrain()->getIdea(1) << std::endl;

    std::cout << "Copy ideas:" << std::endl;
    std::cout << "  ideas[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "  ideas[1]: " << copyDog.getBrain()->getIdea(1) << std::endl;

    // Check if deep copy worked
    if (originalDog.getBrain()->getIdea(0) != copyDog.getBrain()->getIdea(0)) {
        std::cout << "\n✓ DEEP COPY WORKS! (Original and Copy have different Brain objects)" << std::endl;
    } else {
        std::cout << "\n❌ SHALLOW COPY! (Original and Copy share same Brain - BAD!)" << std::endl;
    }

    std::cout << "\n--- Copy assignment test ---" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Dog1: Original idea");
    
    Dog dog2;
    dog2.getBrain()->setIdea(0, "Dog2: Original idea");
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "  dog1 ideas[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "  dog2 ideas[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    // Copy assignment
    dog2 = dog1;
    
    std::cout << "After dog2 = dog1:" << std::endl;
    std::cout << "  dog1 ideas[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "  dog2 ideas[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    dog2.getBrain()->setIdea(0, "Dog2: Modified after assignment");
    
    std::cout << "After modifying dog2:" << std::endl;
    std::cout << "  dog1 ideas[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "  dog2 ideas[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    
    if (dog1.getBrain()->getIdea(0) != dog2.getBrain()->getIdea(0)) {
        std::cout << "✓ Copy assignment is DEEP COPY!" << std::endl;
    }
    
    std::cout << "\n--- Cleanup (Destructors should be called in correct order) ---" << std::endl;

	std::cout << "\n--- Deleting array of Animals ---" << std::endl;
	for (int i = 0; i < 4; i++) {
        delete animals[i];  // Virtual destructor calls Dog::~Dog or Cat::~Cat
    }

	std::cout << "\n=== Without Virtual (WRONG - for comparison) ===" << std::endl;
    
    // This demonstrates what happens without virtual destructor
    WrongAnimal* wrongAnimals[2];
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();

	std::cout << "\n--- Making sounds (WRONG - all same sound) ---" << std::endl;
    for (int i = 0; i < 2; i++) {
        wrongAnimals[i]->makeSound();  // Without virtual - all call WrongAnimal version
    }
    
    std::cout << "\n--- Cleanup (WITHOUT virtual destructor) ---" << std::endl;
    for (int i = 0; i < 2; i++) {
        delete wrongAnimals[i];  // Only WrongAnimal destructor called!
                                 // WrongCat destructor NOT called - memory leak!
    }
    
    return 0;
}