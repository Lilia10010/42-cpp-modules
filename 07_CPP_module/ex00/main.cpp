/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:41:34 by microbiana        #+#    #+#             */
/*   Updated: 2026/06/27 14:30:00 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

// Color codes for prettier output
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"

// A custom class to demonstrate templates working on user-defined types
class Awesome {
public:
	Awesome(void) : _n(0) {}
	Awesome(int n) : _n(n) {}
	Awesome & operator=(Awesome & a) { _n = a._n; return *this; }
	bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
	bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get_n(); return o; }

int main(void)
{
	std::cout << BLUE << "==================================================" << RESET << std::endl;
	std::cout << BLUE << "      CPP Module 07 - ex00: Start of Tests        " << RESET << std::endl;
	std::cout << BLUE << "==================================================" << RESET << std::endl << std::endl;

	// Test 1: Integers
	{
		std::cout << CYAN << "--- Test 1: Integers ---" << RESET << std::endl;
		int a = 2;
		int b = 3;
		std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) =  " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) =  " << ::max(a, b) << std::endl;
		std::cout << std::endl;
	}

	// Test 2: Strings
	{
		std::cout << CYAN << "--- Test 2: Strings ---" << RESET << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "Before swap: c = \"" << c << "\", d = \"" << d << "\"" << std::endl;
		::swap(c, d);
		std::cout << "After swap:  c = \"" << c << "\", d = \"" << d << "\"" << std::endl;
		std::cout << "min(c, d) =  " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) =  " << ::max(c, d) << std::endl;
		std::cout << std::endl;
	}

	// Test 3: Floating point types (double)
	{
		std::cout << CYAN << "--- Test 3: Doubles ---" << RESET << std::endl;
		double p = 3.14159;
		double q = 2.71828;
		std::cout << "Before swap: p = " << p << ", q = " << q << std::endl;
		::swap(p, q);
		std::cout << "After swap:  p = " << p << ", q = " << q << std::endl;
		std::cout << "min(p, q) =  " << ::min(p, q) << std::endl;
		std::cout << "max(p, q) =  " << ::max(p, q) << std::endl;
		std::cout << std::endl;
	}

	// Test 4: Equal Values (Checking min/max behavior)
	{
		std::cout << CYAN << "--- Test 4: Equal Values (Return behavior) ---" << RESET << std::endl;
		int x = 42;
		int y = 42;
		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << "Address of x: " << &x << " | Address of y: " << &y << std::endl;
		
		const int& minVal = ::min(x, y);
		const int& maxVal = ::max(x, y);
		
		std::cout << "min(x, y) value: " << minVal << " | Address returned: " << &minVal 
				  << ( (&minVal == &y) ? GREEN " (Correct: returned y/second)" RESET : RED " (Incorrect)" RESET ) << std::endl;
		std::cout << "max(x, y) value: " << maxVal << " | Address returned: " << &maxVal 
				  << ( (&maxVal == &y) ? GREEN " (Correct: returned y/second)" RESET : RED " (Incorrect)" RESET ) << std::endl;
		std::cout << std::endl;
	}

	// Test 5: Custom Classes (Polymorphic/Object behaviors)
	{
		std::cout << CYAN << "--- Test 5: Custom Class (Awesome) ---" << RESET << std::endl;
		Awesome a(10);
		Awesome b(20);
		std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) =  " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) =  " << ::max(a, b) << std::endl;
		std::cout << std::endl;
	}

	std::cout << BLUE << "==================================================" << RESET << std::endl;
	return 0;
}
