/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidarsharafeev <aidarsharafeev@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 20:52:26 by aidarsharaf       #+#    #+#             */
/*   Updated: 2026/06/13 22:40:39 by aidarsharaf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string replaceAll(std::string line, const std::string& s1, const std::string& s2) {
	size_t position = 0;
	while ((position = line.find(s1, position)) != std::string::npos) {
		line = line.substr(0, position) + s2 + line.substr(position + s1.length());	//substracting evthg before found pos + replacement + everything after
		position += s2.length();	// to move pointer after replaced word not to check it again
	}
	return line;
}

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Usage ./replace filename s1 s2" << std::endl;
		return 1;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	// check if s1 is empty
	if (s1.empty()) {
		std::cerr << "Error: s1 cannot be empty!" << std::endl;
		return 1;
	}

	// opening file to read
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: cannot open the file " << filename << std::endl;
		return 1;
	}

	// Creating file for saving result
	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: cannot create " << outFilename << std::endl;
		return 1;
	}

	// reading from the file line by line
	std::string line;
	while (std::getline(inFile, line)) {
		line = replaceAll(line, s1, s2);	// Replacing char parts
		outFile << line << "\n";			// writing to the output file		
	}

	// closing files
	inFile.close();
	outFile.close();

	return 0;
}

/*
// All the methods needed for this exercise

std::string line = "Hello Bob";

// Find substring - returns position of first char or npos (max size_t value) if not found
line.find("Bob")          // → 6

// Extract a piece of string
line.substr(0, 6)         // → "Hello " (from position 0, length 6)
line.substr(6)            // → "Bob" (from position 6 to end)

// String length
line.length()             // → 9

// Check if string is empty
line.empty()              // → false

// Concatenation — via operator +
"Hello " + "Alice"        // → "Hello Alice"

*/