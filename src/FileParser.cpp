/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileParser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:06:20 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:05:42 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Types.hpp"
#include <cmath>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

t_map readData( std::string filename )
{
	map<EnergyKey, vector<float>> table;
	ifstream	file(filename);
	string	line;
	string	value;

	if (!file.is_open())
	{
		std::cout << "\033[31mFile Error\033[0m\n";
		exit(1);
	}
	vector<float> temp_vals;
	while (std::getline(file,line))
	{
		std::stringstream row(line);
		while (std::getline(row, value, ',')) {
			try {
				float val = std::stof(value);
				temp_vals.push_back(val);
			} catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
		EnergyKey e = {temp_vals[0]};
		std::vector<float> coefficients;
		coefficients.push_back(temp_vals[1]);
		coefficients.push_back(temp_vals[2]);
		coefficients.push_back(temp_vals[3]);
		temp_vals.clear();
		table[e] = coefficients;
	}
	return table;
}
