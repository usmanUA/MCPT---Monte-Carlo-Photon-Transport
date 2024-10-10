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
	t_map table;
	ifstream	file(filename);
	string	line;
	string	value;

	if (!file.is_open())
	{
		std::cout << "\033[31mFile Error\033[0m\n";
		exit(1);
	}
	vector<float> temp_vals;
	std::getline(file,line);
	while (std::getline(file,line))
	{
		//cout << "before inner loop\n";
		std::stringstream row(line);
		while (std::getline(row, value, ',')) {
			//cout << "value from file" << value << "\n";
			try {
				float val = std::stof(value);
				temp_vals.push_back(val);
			} catch (std::exception& e) {
				std::cout << e.what() << "\n";
			}
		}
		/*string key = to_string(temp_vals[0]);*/
		EnergyKey key = {temp_vals[0]};
		map<string, float> coefficients;
		coefficients["u_photo"] = temp_vals[1];
		coefficients["u_comp"] = temp_vals[2];
		coefficients["u_pair"] = temp_vals[3];
		temp_vals.clear();
		table[key] = coefficients;
	}
	return table;
}
