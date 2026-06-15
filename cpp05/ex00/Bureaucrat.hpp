/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 09:58:53 by aelbouz           #+#    #+#             */
/*   Updated: 2026/06/12 11:24:41 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string Name, int Grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception
        {
          public:
            const char *what()  const throw();
        };
        class GradeTooLowException : public std::exception
        {
          public:
            const char *what()  const throw();
        };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif