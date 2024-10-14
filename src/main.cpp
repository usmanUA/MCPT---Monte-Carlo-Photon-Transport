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

#include "SimulationManager.hpp"


t_map readData( std::string filename );

int	main( void )
{
	std::string filename("water_attenuation.csv");
	t_map table;
	table = readData(filename);
	// for (auto row : table)
	// {
	// 	cout << row.first.energy << "\n";
	// }
	SimulationManager	manager	= SimulationManager( 3, table );
	manager.initSimulators();
	manager.manageSimulations();
}
