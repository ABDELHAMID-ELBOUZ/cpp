/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhamid <abdelhamid@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:29:25 by abdelhamid        #+#    #+#             */
/*   Updated: 2025/12/15 21:32:22 by abdelhamid       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : integer(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    integer = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    integer = (int)(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    integer = obj.integer;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)(integer) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return integer >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return integer;
}

void Fixed::seRawBits(int const raw)
{
    integer = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed result;
    result.seRawBits(this->integer + obj.integer);
    return result;
}
Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed result;
    result.seRawBits(this->integer - obj.integer);
    return result;
}
Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed result;
    result.seRawBits((long long)(this->integer * obj.integer) >> fractionalBits);
    return result;
}
Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed result;
    if (obj.integer == 0)
    {
        std::cout << "Division by zero" << std::endl;
        return 1;
    }
    long long tmp = (this->integer << fractionalBits);
    result.seRawBits(tmp / obj.integer);
    return result;
}
bool Fixed::operator>(const Fixed& obj)
{
    if (integer > obj.integer)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator<(const Fixed& obj)
{
    if (integer < obj.integer)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator>=(const Fixed& obj)
{
    if (integer >= obj.integer)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator<=(const Fixed& obj)
{
    if (integer <= obj.integer)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator==(const Fixed& obj)
{
    if (integer == obj.integer)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator!=(const Fixed& obj)
{
    if (integer != obj.integer)
		return (true);
	else
	 	return (false);
}
Fixed& Fixed::operator++()
{
    ++integer;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++integer;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --integer;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --integer;
    return tmp;
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.integer < b.integer)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.integer < b.integer)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.integer > b.integer)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.integer > b.integer)
		return a;
	else
		return b;
}
