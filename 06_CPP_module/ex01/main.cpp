/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:40:33 by microbiana        #+#    #+#             */
/*   Updated: 2026/06/27 14:05:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

// Color codes for prettier output
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

void printData(const std::string& prefix, const Data* data) {
	if (!data) {
		std::cout << prefix << "NULL pointer" << std::endl;
		return;
	}
	std::cout << prefix << "Address: " << data 
			  << " | id: " << data->id 
			  << " | name: \"" << data->name << "\"" 
			  << " | value: " << data->value << std::endl;
}

void runTest(const std::string& testName, Data* originalData) {
	std::cout << CYAN << "=== Test: " << testName << " ===" << RESET << std::endl;
	
	// 1. Show original state
	printData("  [Original]     ", originalData);
	
	// 2. Serialize
	uintptr_t raw = Serializer::serialize(originalData);
	std::cout << YELLOW << "  [Serialized]   Raw integer (decimal): " << RESET << raw << std::endl;
	std::cout << YELLOW << "  [Serialized]   Raw integer (hex):     0x" << RESET 
			  << std::hex << raw << std::dec << std::endl;
	
	// 3. Deserialize
	Data* deserialized = Serializer::deserialize(raw);
	printData("  [Deserialized] ", deserialized);
	
	// 4. Verification
	if (deserialized == originalData) {
		std::cout << GREEN << "  [RESULT]       SUCCESS: Pointers are identical!" << RESET << std::endl;
		if (originalData) {
			if (deserialized->id == originalData->id &&
				deserialized->name == originalData->name &&
				deserialized->value == originalData->value) {
				std::cout << GREEN << "                 SUCCESS: Data members are intact!" << RESET << std::endl;
			} else {
				std::cout << RED << "                 FAILURE: Data members mismatch!" << RESET << std::endl;
			}
		}
	} else {
		std::cout << RED << "  [RESULT]       FAILURE: Pointers do not match!" << RESET << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << BLUE << "==================================================" << RESET << std::endl;
	std::cout << BLUE << "      CPP Module 06 - ex01: Serializer Tests      " << RESET << std::endl;
	std::cout << BLUE << "==================================================" << RESET << std::endl << std::endl;

	// Test 1: Stack Allocated Data
	{
		Data stackData;
		stackData.id = 42;
		stackData.name = "Stack Allocated Object";
		stackData.value = 3.14159;
		runTest("Stack Allocated Data Struct", &stackData);
	}

	// Test 2: Heap Allocated Data
	{
		Data* heapData = new Data;
		heapData->id = 1337;
		heapData->name = "Heap Allocated Object";
		heapData->value = 2.71828;
		runTest("Heap Allocated Data Struct", heapData);
		delete heapData;
	}

	// Test 3: Null Pointer
	{
		runTest("Null Pointer Serialization", NULL);
	}

	std::cout << BLUE << "==================================================" << RESET << std::endl;
	return 0;
}
