/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:04:44 by microbiana        #+#    #+#             */
/*   Updated: 2026/01/12 11:16:39 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossProduct(Point const& a, Point const& b, Point const& p)
{
    return (
        (b.getX() - a.getX()) * (p.getY() - a.getY())
        - (b.getY() - a.getY()) * (p.getX() - a.getX())
    );
    
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ab = crossProduct(a, b, point);
    Fixed bc = crossProduct(b, c, point);
    Fixed ca = crossProduct(c, a, point);

    if (ab == 0 || bc == 0 || ca == 0)
        return (false);

    bool hasPositive = (ab > 0) && (bc > 0) && (ca > 0);
    bool hasNegative = (ab < 0) && (bc < 0) && (ca < 0);

    return ( hasPositive || hasNegative);
}