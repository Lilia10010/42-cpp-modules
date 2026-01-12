/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:58:57 by microbiana        #+#    #+#             */
/*   Updated: 2026/01/12 11:04:30 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point&::Point::operator=(const Point& other)
{
    (void)other;
    return (*this);
}

Point::~Point() {}

Fixed Point::getX() const { return (_x); }

Fixed Point::getY() const { return (_y); }