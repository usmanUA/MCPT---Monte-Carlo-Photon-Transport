/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:27:13 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/08 11:49:16 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "SimulationManager.hpp"

readData( std::string filename );

int	main( void )
{
	std::string filename("water_attenuation.csv");
	std::map<EnergyKey, std::vector<float>> table;
	table = readData(filename);
	SimulationManager	manager	= SimulationManager();
}
