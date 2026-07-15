/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 09:58:53 by aelbouz           #+#    #+#             */
/*   Updated: 2026/07/14 09:06:07 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string& Name, int Grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
		void signForm(Form& form);
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