/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:49:17 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 12:24:20 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name)
{
    // Verifica se o valor é válido ANTES de criar o objeto
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        // _name é const, não pode ser reassinado
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    // subir grade = diminuir número
    if (_grade <= 1)
        throw GradeTooHighException();

    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();

    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

//objetivo: 1. Definir como o objeto será representado externamente
// 2. Serve para definir como o objeto é inserido em um fluxo de saída
//abstração && encapsulamento && polimorfismo ad-hoc (overload)
//Mesmo operador <<, comportamentos diferentes 
//pode definir o formato da saida ex json => os << "{ \"name\": \"" << b.getName() << "\" }"; // JSON
// Sim → normalmente usado para imprimir
// Mas → o objetivo real é integrar o objeto ao sistema de streams do C++
// É uma forma de tornar seu objeto idiomático em C++
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName()
       << ", bureaucrat grade "
       << b.getGrade();
    return os;
}