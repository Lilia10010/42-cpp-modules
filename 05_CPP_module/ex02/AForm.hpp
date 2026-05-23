/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:09:29 by microbiana        #+#    #+#             */
/*   Updated: 2026/05/23 16:14:37 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // forward declaration

/*
    AForm = classe ABSTRATA

    Objetivo:
    - Servir de base para todos os formulários
    - Definir contrato comum (execute)
*/

class AForm {
protected:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
// Construtor
    AForm();
    AForm(const std::string& name, int sign, int exec);

    // Forma Canônica
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Lógica de assinatura
    void beSigned(const Bureaucrat& b);


    virtual void execute(Bureaucrat const & executor) const = 0;

    // Exceções
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// operador <<
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif