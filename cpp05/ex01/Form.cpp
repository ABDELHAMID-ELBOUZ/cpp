/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:17:02 by aelbouz           #+#    #+#             */
/*   Updated: 2025/12/30 09:27:06 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    std::cout << "Form copy assignment operator called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const 
{ 
    return name; 
}

bool Form::getIsSigned() const 
{ 
    return isSigned; 
}

int Form::getGradeToSign() const 
{ 
    return gradeToSign; 
}

int Form::getGradeToExecute() const 
{ 
    return gradeToExecute; 
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName()
       << ", signed: " << f.getIsSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}
