/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelhamid <abdelhamid@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:09 by abdelhamid        #+#    #+#             */
/*   Updated: 2025/12/14 15:51:22 by abdelhamid       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int raw_bits;
		const static int fractional_bits = 8;
	public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits(int const raw);
};

#endif