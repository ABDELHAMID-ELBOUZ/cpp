/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:02:09 by aelbouz           #+#    #+#             */
/*   Updated: 2026/06/12 11:24:49 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade): name(Name), grade(Grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called " << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;
    std::cout << "Bureaucrat copy assignement called" << std::endl;
    return *this;
}

std::string Bureaucrat::getName()
{
    return name;
}

int Bureaucrat::getGrade()
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
        throw GradeTooHighException();
	grade--;
}
void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
        throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

std::ostream& operator<<( std::ostream &os,  Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
