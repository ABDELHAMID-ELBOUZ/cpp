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
#include <cstring>

Fixed::Fixed() : rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    rawBits = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    rawBits = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        rawBits = rhs.rawBits;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return rawBits >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}

void Fixed::setRawBits(int const raw)
{
    rawBits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed result;
    result.setRawBits(this->rawBits + obj.rawBits);
    return result;
}
Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed result;
    result.setRawBits(this->rawBits - obj.rawBits);
    return result;
}
Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed result;
    result.setRawBits(this->rawBits * obj.rawBits);
    return result;
}
Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed result;
    result.setRawBits(this->rawBits / obj.rawBits);
    return result;
}
bool Fixed::operator>(const Fixed& obj)
{
    if (rawBits > obj.rawBits)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator<(const Fixed& obj)
{
    if (rawBits < obj.rawBits)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator>=(const Fixed& obj)
{
    if (rawBits >= obj.rawBits)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator<=(const Fixed& obj)
{
    if (rawBits <= obj.rawBits)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator==(const Fixed& obj)
{
    if (rawBits == obj.rawBits)
		return (true);
	else
	 	return (false);
}
bool Fixed::operator!=(const Fixed& obj)
{
    if (rawBits != obj.rawBits)
		return (true);
	else
	 	return (false);
}
Fixed& Fixed::operator++()
{
    ++rawBits;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++rawBits;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --rawBits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --rawBits;
    return tmp;
}
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.rawBits < b.rawBits)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.rawBits < b.rawBits)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.rawBits > b.rawBits)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.rawBits > b.rawBits)
		return a;
	else
		return b;
}
