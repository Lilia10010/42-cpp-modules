/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:41:01 by microbiana        #+#    #+#             */
/*   Updated: 2026/06/27 14:05:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

// Color codes for prettier output
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

Base* generate(void) {
	int random = std::rand() % 3;
	switch (random) {
		case 0:
			std::cout << "Generated: " << GREEN << "A" << RESET << std::endl;
			return new A();
		case 1:
			std::cout << "Generated: " << GREEN << "B" << RESET << std::endl;
			return new B();
		default:
			std::cout << "Generated: " << GREEN << "C" << RESET << std::endl;
			return new C();
	}
}

void identify(Base* p) {
	if (!p) {
		std::cout << RED << "NULL pointer (cannot identify)" << RESET << std::endl;
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "A (identified via pointer casting)" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "B (identified via pointer casting)" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "C (identified via pointer casting)" << RESET << std::endl;
	else
		std::cout << YELLOW << "Unknown class (Base type only)" << RESET << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN << "A (identified via reference casting)" << RESET << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << GREEN << "B (identified via reference casting)" << RESET << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << GREEN << "C (identified via reference casting)" << RESET << std::endl;
		return;
	} catch (std::exception&) {}

	std::cout << YELLOW << "Unknown class (Base type only)" << RESET << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	std::cout << BLUE << "==================================================" << RESET << std::endl;
	std::cout << BLUE << "      CPP Module 06 - ex02: Real Type Detection   " << RESET << std::endl;
	std::cout << BLUE << "==================================================" << RESET << std::endl << std::endl;

	// Part 1: Standard Tests (5 random instances)
	std::cout << CYAN << "--- PART 1: Identifying Random Instances ---" << RESET << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << "Test " << i + 1 << ":" << std::endl;
		Base* ptr = generate();

		std::cout << "  Identify by pointer:   ";
		identify(ptr);

		std::cout << "  Identify by reference: ";
		identify(*ptr);

		delete ptr;
		std::cout << std::endl;
	}

	// Part 2: Edge Cases (NULL pointer and pure Base class instance)
	std::cout << CYAN << "--- PART 2: Edge Cases ---" << RESET << std::endl;
	
	std::cout << "Test 6 (NULL Pointer):" << std::endl;
	Base* nullPtr = NULL;
	std::cout << "  Identify by pointer:   ";
	identify(nullPtr);
	std::cout << std::endl;

	std::cout << "Test 7 (Pure Base Class Instance):" << std::endl;
	// Create a pure Base instance that is NOT A, B, or C
	Base* rawBase = new Base();
	
	std::cout << "  Identify by pointer:   ";
	identify(rawBase);
	
	std::cout << "  Identify by reference: ";
	identify(*rawBase);
	
	delete rawBase;
	std::cout << std::endl;

	std::cout << BLUE << "==================================================" << RESET << std::endl;
	return 0;
}
