#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), isSigned(false), gradeToSign(150), gradeToExec(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& Name, int grade_To_Sign, int grade_To_Exec) 
    : name(Name), isSigned(false), gradeToSign(grade_To_Sign), gradeToExec(grade_To_Exec) 
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other) 
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
    std::cout << "Form copy constructor called " << std::endl;
}

Form& Form::operator=(const Form& other) 
{
    if (this != &other)
        this->isSigned = other.isSigned;
    std::cout << "Form copy assignement called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
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
int Form::getGradeToExec() const
{ 
	return gradeToExec; 
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() > gradeToSign) 
        throw Form::GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form " << form.getName() 
       << ", status: " << (form.getIsSigned() ? "signed" : "unsigned")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExec();
    return os;
}
