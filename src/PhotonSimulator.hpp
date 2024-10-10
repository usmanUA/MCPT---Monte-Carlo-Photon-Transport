/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhotonSimulator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:45:14 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:07:37 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Types.hpp"
#include "Photon.hpp"
#include <map>

class	PhotonSimulator
{
	public:
		// NOTE: Canonical Form
		PhotonSimulator( void );
		PhotonSimulator( Position&, Direction&, float& , t_map& );
		~PhotonSimulator( void );
		/*PhotonSimulator( const PhotonSimulator& );*/
		/*PhotonSimulator&	operator=( const PhotonSimulator& );*/

		void	simulate( void );
		void	updatePhotonPosition( const float& );
		void	updatePhotonDirection( const float& theta, const float& phi );
		void	updatePhotonEnergy( const float& );
	private:
		Photon* photon;
		t_map& table;
		map<string, float> coefficients;
};
