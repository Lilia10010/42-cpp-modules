/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:09:29 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 13:25:58 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

/*
    Classe Form

    Representa um formulário que:
    - pode ser assinado
    - exige um nível mínimo para assinatura
    - exige outro nível para execução
*/

class Form {
private:
    const std::string _name;      // nome do formulário (imutável)
    bool _isSigned;               // estado (assinado ou não)
    const int _gradeToSign;       // grade mínima para assinar
    const int _gradeToExecute;    // grade mínima para executar

public:
    Form(const std::string& name, int gradeToSign, int gradeToExecute);

    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Recebe um Bureaucrat e tenta assinar
    void beSigned(const Bureaucrat& b);

  
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif