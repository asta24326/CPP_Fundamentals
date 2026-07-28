/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:36:33 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/07/28 22:48:45 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "=== With Virtual (Correct Polymorphism) ===" << std::endl;
	
	Animal* animals[3];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();

	std::cout << "\n--- Making sounds (correct) ---" << std::endl;
    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();
    }

	std::cout << "\n--- Copy constructor ---" << std::endl;
    Dog* dog = new Dog();
    Dog* dogCopy = new Dog(*dog);
    
    std::cout << "\n--- Copy assignment ---" << std::endl;
    Dog* dog2 = new Dog();
    *dog2 = *dog;
    
    std::cout << "\n--- Cleanup ===" << std::endl;

	std::cout << "\n--- Copied/created objects ===" << std::endl;
    delete dog;
    delete dogCopy;
    delete dog2;

	std::cout << "\n--- Array created objects ===" << std::endl;
	for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

	std::cout << "\n=== Without Virtual (Wrong!) ===" << std::endl;
    
    WrongAnimal* wrongAnimals[2];
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();

	std::cout << "\n--- Making sounds (WRONG!) ---" << std::endl;
    for (int i = 0; i < 2; i++) {
        wrongAnimals[i]->makeSound();
    }
    
    std::cout << "\n--- Cleanup ===" << std::endl;
    for (int i = 0; i < 2; i++) {
        delete wrongAnimals[i];
    }
    
    return 0;

}