/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:41:45 by microbiana        #+#    #+#             */
/*   Updated: 2026/06/27 14:30:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Color codes for prettier output
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// A print function template to print elements of any streamable type
template <typename T>
void printElement(T const &elem)
{
	std::cout << elem << " ";
}

// A function to modify integers (increment)
void increment(int &n)
{
	n++;
}

// A function to modify chars (to uppercase)
void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}

// Custom class to show compatibility with objects
class Awesome {
public:
	Awesome(void) : _n(42) {}
	int get(void) const { return this->_n; }
private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

int main(void)
{
	std::cout << BLUE << "==================================================" << RESET << std::endl;
	std::cout << BLUE << "      CPP Module 07 - ex01: Iter Tests            " << RESET << std::endl;
	std::cout << BLUE << "==================================================" << RESET << std::endl << std::endl;

	// Test 1: Int Array & Modification
	{
		std::cout << CYAN << "--- Test 1: Integer Array & Mutator ---" << RESET << std::endl;
		int intArray[] = {1, 2, 3, 4, 5};
		size_t len = sizeof(intArray) / sizeof(intArray[0]);

		std::cout << "Original:        ";
		::iter(intArray, len, printElement<int>);
		std::cout << std::endl;

		// Mutate using increment
		::iter(intArray, len, increment);

		std::cout << "After increment: ";
		::iter(intArray, len, printElement<int>);
		std::cout << std::endl << std::endl;
	}

	// Test 2: Char Array & Mutation
	{
		std::cout << CYAN << "--- Test 2: Char Array & Mutator ---" << RESET << std::endl;
		char charArray[] = {'a', 'b', 'c', 'd'};
		size_t len = sizeof(charArray) / sizeof(charArray[0]);

		std::cout << "Original:      ";
		::iter(charArray, len, printElement<char>);
		std::cout << std::endl;

		// Mutate to uppercase
		::iter(charArray, len, toUpper);

		std::cout << "After toUpper: ";
		::iter(charArray, len, printElement<char>);
		std::cout << std::endl << std::endl;
	}

	// Test 3: String Array
	{
		std::cout << CYAN << "--- Test 3: String Array (ReadOnly print) ---" << RESET << std::endl;
		std::string strArray[] = {"hello", "world", "42", "cursus"};
		size_t len = sizeof(strArray) / sizeof(strArray[0]);

		std::cout << "Strings: ";
		::iter(strArray, len, printElement<std::string>);
		std::cout << std::endl << std::endl;
	}

	// Test 4: Const Integer Array (Ensures read-only compatibility)
	{
		std::cout << CYAN << "--- Test 4: Const Integer Array ---" << RESET << std::endl;
		int const constArray[] = {10, 20, 30, 40};
		
		std::cout << "Const ints: ";
		::iter(constArray, 4, printElement<int>);
		std::cout << std::endl << std::endl;
	}

	// Test 5: Custom Class Array (Awesome class)
	{
		std::cout << CYAN << "--- Test 5: Custom Class (Awesome) Array ---" << RESET << std::endl;
		Awesome awesomeArray[3];
		
		std::cout << "Awesomes: ";
		::iter(awesomeArray, 3, printElement<Awesome>);
		std::cout << std::endl << std::endl;
	}

	std::cout << BLUE << "==================================================" << RESET << std::endl;
	return 0;
}
