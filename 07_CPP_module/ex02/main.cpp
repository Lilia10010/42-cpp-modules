/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:42:00 by microbiana        #+#    #+#             */
/*   Updated: 2026/06/27 14:30:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

// Color codes for prettier output
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

#define MAX_VAL 750

static void testEmptyArray()
{
	std::cout << CYAN << "=== Test 1: Empty Array ===" << RESET << std::endl;
	Array<int> empty;
	std::cout << "  Empty array size: " << empty.size() << std::endl;
	try
	{
		std::cout << "  Attempting to write to empty[0]..." << std::endl;
		empty[0] = 1;
		std::cout << RED << "  [RESULT] FAILURE: Did not throw exception!" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "  [RESULT] SUCCESS: Caught expected exception: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void testConstArray()
{
	std::cout << CYAN << "=== Test 2: Const Array Access ===" << RESET << std::endl;
	const Array<int> constArr(5);
	std::cout << "  Const array size: " << constArr.size() << std::endl;
	try
	{
		std::cout << "  Reading constArr[0] (should be default initialized): " << constArr[0] << std::endl;
		std::cout << GREEN << "  [RESULT] SUCCESS: Successfully read const element" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "  [RESULT] FAILURE: Exception thrown on valid read: " << RESET << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void testDeepCopy()
{
	std::cout << CYAN << "=== Test 3: Deep Copy & Independence ===" << RESET << std::endl;
	Array<int> original(3);
	original[0] = 42;
	original[1] = 21;
	original[2] = 84;

	std::cout << "  Creating copyConstructed and copyAssigned from original..." << std::endl;
	Array<int> copyConstructed(original);
	Array<int> copyAssigned;
	copyAssigned = original;

	std::cout << "  Modifying copies (should not affect original)..." << std::endl;
	copyConstructed[0] = 100;
	copyAssigned[1] = 200;

	std::cout << "    Original[0]:        " << original[0] << " (expected 42)" << std::endl;
	std::cout << "    Original[1]:        " << original[1] << " (expected 21)" << std::endl;
	std::cout << "    CopyConstructed[0]: " << copyConstructed[0] << " (expected 100)" << std::endl;
	std::cout << "    CopyAssigned[1]:    " << copyAssigned[1] << " (expected 200)" << std::endl;

	if (original[0] == 42 && original[1] == 21 && copyConstructed[0] == 100 && copyAssigned[1] == 200)
	{
		std::cout << GREEN << "  [RESULT] SUCCESS: Deep copies are independent!" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "  [RESULT] FAILURE: Deep copy failed, modifications leak!" << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void testStringType()
{
	std::cout << CYAN << "=== Test 4: Array of std::string ===" << RESET << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "42";

	std::cout << "  strings[0]: " << strings[0] << std::endl;
	std::cout << "  strings[1]: " << strings[1] << std::endl;
	std::cout << "  strings[2]: " << strings[2] << std::endl;
	std::cout << "  Size:       " << strings.size() << std::endl;
	
	if (strings.size() == 3 && strings[0] == "Hello")
	{
		std::cout << GREEN << "  [RESULT] SUCCESS: Templates work with complex types (std::string)" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "  [RESULT] FAILURE: String array behavior incorrect" << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void testOriginalSubject()
{
	std::cout << CYAN << "=== Test 5: Original Subject Verification (Mirror Test) ===" << RESET << std::endl;
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	
	std::srand(std::time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "  Checking copies and scope destruction..." << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	} // test and tmp are destroyed here

	bool success = true;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << RED << "  [RESULT] FAILURE: Values changed after copies/destruction!" << RESET << std::endl;
			success = false;
			break;
		}
	}
	if (success)
	{
		std::cout << GREEN << "  [RESULT] SUCCESS: All " << MAX_VAL << " mirror values matched!" << RESET << std::endl;
	}

	// Testing boundary exceptions
	try
	{
		std::cout << "  Accessing numbers[-2] (should throw)..." << std::endl;
		numbers[-2] = 0;
		std::cout << RED << "  [RESULT] FAILURE: Out of bounds negative index did not throw!" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "  [RESULT] SUCCESS: Caught exception for negative index: " << RESET << e.what() << std::endl;
	}

	try
	{
		std::cout << "  Accessing numbers[MAX_VAL] (should throw)..." << std::endl;
		numbers[MAX_VAL] = 0;
		std::cout << RED << "  [RESULT] FAILURE: Out of bounds positive index did not throw!" << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << GREEN << "  [RESULT] SUCCESS: Caught exception for positive index: " << RESET << e.what() << std::endl;
	}

	delete[] mirror;
	std::cout << std::endl;
}

int main()
{
	std::cout << BLUE << "==================================================" << RESET << std::endl;
	std::cout << BLUE << "      CPP Module 07 - ex02: Array Class Tests     " << RESET << std::endl;
	std::cout << BLUE << "==================================================" << RESET << std::endl << std::endl;

	testEmptyArray();
	testConstArray();
	testDeepCopy();
	testStringType();
	testOriginalSubject();

	std::cout << BLUE << "==================================================" << RESET << std::endl;
	return 0;
}
