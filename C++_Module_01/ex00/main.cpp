/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:50:58 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/17 10:54:24 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Zombie.hpp" // gives us access to the Zombie class and functions

int main()
{
	// Allocating a zombie object on the heap
	Zombie *heapZombie = newZombie("The Heap Zombie");
	
	// Utilize zombie object's function to announce itself
	heapZombie->announce();


	// Allocate and automatically destroy a zombie on the stack
	randomChump("The Stack zombie");

	// Deallocate heap memory explicitly to prevent leaks
	delete heapZombie;

	return 0;
}