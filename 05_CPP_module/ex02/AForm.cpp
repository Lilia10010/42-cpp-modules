/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:11:38 by microbiana        #+#    #+#             */
/*   Updated: 2026/05/23 16:07:54 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int sign, int exec)
    : _name(name), _isSigned(false), _gradeToSign(sign), _gradeToExecute(exec)
{
    // validação de limites
    if (sign < 1 || exec < 1)
        throw GradeTooHighException();

    if (sign > 150 || exec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (_isSigned)
        throw std::runtime_error("Form already signed");

    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName()
       << ", signed: " << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();

    return os;
}