/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimulationManager.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:50:19 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:30:42 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PhotonSimulator.hpp"
#include <memory>
#include <vector>

class	SimulationManager
{
	public:
		//SimulationManager( void );
		SimulationManager( int, t_map& );
		//~SimulationManager( void );
		/*SimulationManager( const SimulationManager& ) = delete;*/
		/*SimulationManager&	operator=( const SimulationManager& ) = delete;*/

		void initSimulators( void );
		void	manageSimulations( void );

	private:
		int	N;
		t_map&	table;
		vector<unique_ptr<PhotonSimulator> >	simulators;
};
