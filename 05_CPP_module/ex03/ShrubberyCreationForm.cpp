/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:38:05 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 17:46:04 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    // 🔥 regra obrigatória
    if (!getIsSigned())
        throw std::runtime_error("Form not signed");

    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    // 🔥 cria arquivo
    std::ofstream file((_target + "_shrubbery").c_str());

    file << "  🌳\n 🌳🌳\n🌳🌳🌳\n";
}