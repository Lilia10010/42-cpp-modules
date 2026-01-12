/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 15:23:28 by microbiana        #+#    #+#             */
/*   Updated: 2026/01/12 11:16:03 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include "Point.hpp"

// Declaração da função bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

    // =========================
    // Triângulo base
    // =========================
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    // =========================
    // Caso 1: ponto DENTRO
    // =========================
    Point inside(2.0f, 2.0f);
    std::cout << "Inside (esperado: 1): "
              << bsp(a, b, c, inside) << std::endl;

    // =========================
    // Caso 2: ponto FORA
    // =========================
    Point outside(20.0f, 20.0f);
    std::cout << "Outside (esperado: 0): "
              << bsp(a, b, c, outside) << std::endl;

    // =========================
    // Caso 3: ponto na ARESTA
    // =========================
    Point edge(5.0f, 0.0f);
    std::cout << "Edge (esperado: 0): "
              << bsp(a, b, c, edge) << std::endl;

    // =========================
    // Caso 4: ponto no VÉRTICE
    // =========================
    Point vertex(0.0f, 0.0f);
    std::cout << "Vertex (esperado: 0): "
              << bsp(a, b, c, vertex) << std::endl;

    // =========================
    // Caso 5: triângulo invertido
    // =========================
    Point inside_inverted(2.0f, 2.0f);
    std::cout << "Inside inverted (esperado: 1): "
              << bsp(c, b, a, inside_inverted) << std::endl;

    return 0;
}
