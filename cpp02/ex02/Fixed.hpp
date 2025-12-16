/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhamid <abdelhamid@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:09 by abdelhamid        #+#    #+#             */
/*   Updated: 2025/12/15 21:28:39 by abdelhamid       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 integer;
    static const int    fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& obj);
    ~Fixed();
    Fixed(const int value);
    Fixed(const float value);
    float toFloat(void) const;
    int   toInt(void) const;
    int  getRawBits(void) const;
    void seRawBits(int const raw);
	Fixed operator+(const Fixed& obj);
    Fixed operator*(const Fixed& obj);
    Fixed operator-(const Fixed& obj);
    Fixed operator/(const Fixed& obj);
	bool operator==(const Fixed& obj);
    bool operator!=(const Fixed& obj);
    bool operator>=(const Fixed& obj);
    bool operator<=(const Fixed& obj);
	bool operator>(const Fixed& obj);
    bool operator<(const Fixed& obj);
	Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
	static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
