/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:11:38 by microbiana        #+#    #+#             */
/*   Updated: 2026/04/26 13:43:13 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    // validação de invariantes
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // _name, _gradeToSign e _gradeToExecute são const, não podem ser reassinados
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const { return _name; }
bool        Form::getIsSigned() const { return _isSigned; }
int         Form::getGradeToSign() const { return _gradeToSign; }
int         Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& b)
{
    // verifica se o burocrata tem nível suficiente
    if (_isSigned)
        throw std::logic_error("Form already signed");

    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

    _isSigned = true;
}



const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.getName()
       << ", signed: " << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();

    return os;
}