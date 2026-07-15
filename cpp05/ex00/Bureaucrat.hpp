/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhamid <abdelhamid@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 09:58:53 by aelbouz           #+#    #+#             */
/*   Updated: 2026/07/15 16:25:08 by abdelhamid       ###   ########.fr       */
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
        Bureaucrat(const std::string& Name, int Grade);
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        std::string getName() const; 
        int getGrade() const; 
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif