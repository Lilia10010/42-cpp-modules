/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:10:58 by microbiana        #+#    #+#             */
/*   Updated: 2026/01/10 15:21:54 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>


//forma canônica 
Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        _rawBits = other._rawBits;
    return (*this);
}

Fixed::~Fixed() {}

//construtores
Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    _rawBits = roundf(value * (1 << _fractionalBits));
}

//conversões
float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

//operadores de comparação
bool Fixed::operator>(const Fixed& other) const {
    return _rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return _rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _rawBits != other._rawBits;
}


//operadores aritiméticos
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_rawBits + other._rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_rawBits - other._rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long tmp = (long)_rawBits * other._rawBits;
    result.setRawBits(tmp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long tmp = ((long)_rawBits << _fractionalBits) / other._rawBits;
    result.setRawBits(tmp);
    return result;
}


//incremento e decremento
Fixed& Fixed::operator++() {
    _rawBits += 1;
    return *this;
}

// Pós
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawBits += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    _rawBits -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawBits -= 1;
    return temp;
}


// min - max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}


int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}


//operador de inserção [operador << (polimorfismo ad-hoc)]
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
