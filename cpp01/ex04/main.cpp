/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouz <aelbouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 10:28:09 by aelbouz           #+#    #+#             */
/*   Updated: 2025/10/07 10:42:40 by aelbouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "error usage " << av[0] << " file s1 s2 " << std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::ifstream in_File(filename.c_str());
    if (!in_File.is_open())
    {
        std::cout << "Error: Could not open input file '" << filename << "'" << std::endl;
        return 1;
    }
    std::string outfilename = filename + ".replace";
    std::ofstream out_File(outfilename.c_str());
    if (!out_File.is_open())
    {
        std::cout << "Error: Could not open output file '" << outfilename << "'" << std::endl;
        in_File.close();
        return 1;
    }
    std::string line;
    while (std::getline(in_File,line))
    {
        if (!in_File.eof() )
            line += "\n";
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) 
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        out_File << line;
    }
    //in_File.close();
    //out_File.close();
}
