/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:04:09 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/04 14:07:06 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <string>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    void complain( std::string level );
};