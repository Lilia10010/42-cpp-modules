/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 11:51:41 by microbiana        #+#    #+#             */
/*   Updated: 2026/05/23 16:16:37 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// forward declaration to avoid cyclic include with Form
class AForm;

/*
    Classe Bureaucrat

    Representa uma entidade com:
    - nome (imutável)
    - grade (controlado entre 1 e 150)

    Objetivo:
    - Garantir que nunca exista um Bureaucrat inválido
    - Usar exceções para proteger o estado
*/

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(const std::string& name, int grade);


    Bureaucrat(const Bureaucrat& other); //copy constructor (cria ob novo apartir de outro)
    Bureaucrat& operator=(const Bureaucrat& other); // copy assingnment (opera em ob já existente)
    ~Bureaucrat();


    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& form);    
    void executeForm(AForm const & form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

// Operador <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif