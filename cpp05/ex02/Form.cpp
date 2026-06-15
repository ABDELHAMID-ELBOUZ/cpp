#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{

}

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    std::cout << "Form copy constructor called " << std::endl;
}

Form& Form::operator=(const Form& other) 
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    std::cout << "Form copy assignement called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	 return _name; 
}
bool Form::getIsSigned() const
{
	 return _isSigned; 
}
int Form::getGradeToSign() const
{ 
	return _gradeToSign; 
}
int Form::getGradeToExec() const
{ 
	return _gradeToExec; 
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() > _gradeToSign) 
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) 
{
    os << "Form " << form.getName() 
       << ", status: " << (form.getIsSigned() ? "signed" : "unsigned")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExec();
    return os;
}
