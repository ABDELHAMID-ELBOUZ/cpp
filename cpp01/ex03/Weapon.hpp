/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:50:00 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/07 11:30:57 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon(const std::string &Type);
    const std::string &getType() const;
    void setType(const std::string& newType);
};

#endif