/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimulationManager.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:03:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:36:44 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimulationManager.hpp"
#include "Photon.hpp"
#include "PhotonSimulator.hpp"
#include <memory>

SimulationManager::SimulationManager( int n, t_map& table ) : N(n), table(table)
{};

void SimulationManager::initSimulators( void )
{
	Position pos {0, 0, 0};
	Direction dir {1, 0, 0};

	for (int i = 0; i < N; i++)
	{
		this->simulators.push_back(std::make_unique<PhotonSimulator>(pos, dir, 0.0001, table));
	}
}

void	SimulationManager::manageSimulations( void )
{

}

